#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cstdlib>
#include <vector>
using namespace std;
struct IntHash
{
    size_t operator()(uint32_t key) const
    {
        return key * 2654435761U;
    };
};
template <typename F>
uint64_t measure(F &&func)
{
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}
int main()
{
    const int N = 500000;
    vector<pair<uint32_t, float>> data;
    data.reserve(N);
    for (int i = 0; i < N; i++)
    {
        data.emplace_back(rand() % 1000000, (float)rand() / RAND_MAX);
    }
    auto t_map_insert = measure([&]()
                                {
        map<uint32_t ,float>m;
        for(const auto&p:data)m.emplace(p.first,p.second); });

    auto t_map_query = measure([&]()
                               {
        map<uint32_t, float> m;
        for (const auto &p : data)
            m.emplace(p.first, p.second);
        for (int i = 0; i < 100000; ++i)
        {
            auto it = m.find(rand() % 1000000);
            (void)it; // 避免编译器优化
        } });
    // 2. 测试unordered_map（默认哈希）
    auto t_umap_def_insert = measure([&]()
                                     {
        std::unordered_map<uint32_t, float> um;
        um.reserve(N); // 预分配桶，关键！
        for (const auto& p : data) um.emplace(p.first, p.second); });

    auto t_umap_def_query = measure([&]()
                                    {
        std::unordered_map<uint32_t, float> um;
        um.reserve(N);
        for (const auto& p : data) um.emplace(p.first, p.second);
        for (int i = 0; i < 100000; ++i) {
            auto it = um.find(rand() % 1000000);
            (void)it;
        } });
    // 3. 测试unordered_map（自定义哈希）
    auto t_umap_custom_insert = measure([&]()
                                        {
        std::unordered_map<uint32_t, float, IntHash> um;
        um.reserve(N);
        for (const auto& p : data) um.emplace(p.first, p.second); });

    auto t_umap_custom_query = measure([&]()
                                       {
        std::unordered_map<uint32_t, float, IntHash> um;
        um.reserve(N);
        for (const auto& p : data) um.emplace(p.first, p.second);
        for (int i = 0; i < 100000; ++i) {
            auto it = um.find(rand() % 1000000);
            (void)it;
        } });

    // 输出结果
    std::cout << "map " << t_map_insert << "us" << t_map_query - t_map_insert << "us\n";
    std::cout << "unordered_map " << t_umap_def_insert << "us" << t_umap_def_query - t_umap_def_insert << "us\n";
    std::cout << "unordered_map " << t_umap_custom_insert << "us" << t_umap_custom_query - t_umap_custom_insert << "us\n";

    return 0;
}