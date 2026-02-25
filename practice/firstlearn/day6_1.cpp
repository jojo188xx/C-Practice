#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
struct Data
{
    int id;
    string name;
    Data(int id_, string name_) : id(id_), name(move(name_)) {}
    Data(const Data &) = delete;            // 禁止拷贝构造
    Data &operator=(const Data &) = delete; // 禁止拷贝赋值
    Data(Data &&) = default;                // 移动构造
    Data &operator=(Data &&) = default;     // 移动赋值
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
    const int N = 1000000; // 100万条数据
    // 1. 测试：无reserve + push_back
    auto t1 = measure([&]()
                      {
        std::vector<Data> vec;
        for (int i = 0; i < N; ++i) {
            vec.push_back(Data(i, "test" + std::to_string(i))); // 临时对象+拷贝
        } });

    // 2. 测试：reserve + emplace_back
    auto t2 = measure([&]()
                      {
        std::vector<Data> vec;
        vec.reserve(N); // 预分配内存
        for (int i = 0; i < N; ++i) {
            vec.emplace_back(i, "test" + std::to_string(i)); // 原地构造
        } });

    // 3. 测试遍历效率
    std::vector<Data> vec;
    vec.reserve(N);
    for (int i = 0; i < N; ++i)
        vec.emplace_back(i, "test");

    // 3.1 低效遍历（多次size()）
    auto t3 = measure([&]()
                      {
        int sum = 0;
        for (int i = 0; i < vec.size(); ++i) sum += vec[i].id; });

    // 3.2 优化遍历（预存size()）
    auto t4 = measure([&]()
                      {
        int sum = 0;
        const size_t size = vec.size();
        for (size_t i = 0; i < size; ++i) sum += vec[i].id; });

    // 3.3 最优遍历（范围for+引用）
    auto t5 = measure([&]()
                      {
        int sum = 0;
        for (const auto& d : vec) sum += d.id; });

    // 输出结果
    std::cout << "no reserve+push_back=" << t1 << "us\n";
    std::cout << "reserve+emplace_back=" << t2 << "us\n";
    std::cout << "low=" << t3 << "us\n";
    std::cout << "size=" << t4 << "us\n";
    std::cout << "for=" << t5 << "us\n";

    return 0;
}