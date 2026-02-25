#include <iostream>
#include <vector>
#include <chrono>
#include <cstdint>

// 嵌入式场景：紧凑特征结构体（紧凑内存布局）
struct Feature
{
    uint32_t id;        // 特征ID（固定长度，避免内存碎片）
    float value;        // 特征值
    uint8_t type;       // 特征类型（1字节，节省内存）
    uint8_t padding[3]; // 内存对齐，补3字节

    // 构造函数
    Feature(uint32_t id_, float value_, uint8_t type_)
        : id(id_), value(value_), type(type_) {}
    // 移动构造（避免拷贝，提升性能）
    Feature(Feature &&other) noexcept = default;
    Feature &operator=(Feature &&other) noexcept = default;
    // 禁用拷贝（强制移动，减少性能损耗）
    Feature(const Feature &) = delete;
    Feature &operator=(const Feature &) = delete;
};

// 修复后的轻量级SmallVector（栈分配，固定大小，无堆操作）
template <typename T, size_t MAX_SIZE>
struct SmallVector
{
    T data[MAX_SIZE]; // 栈数组
    size_t size = 0;  // 当前元素数

    // ========== 核心修复：显式声明默认构造函数 ==========
    SmallVector() = default; // 允许无参构造

    // 原地构造元素（placement new）
    template <typename... Args>
    void emplace_back(Args &&...args)
    {
        if (size < MAX_SIZE)
        {
            // 定位new：在指定内存地址构造对象
            new (&data[size]) T(std::forward<Args>(args)...);
            size++;
        }
    }

    // 手动析构（栈对象析构时，需要手动调用元素的析构函数）
    ~SmallVector()
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i].~T(); // 调用T的析构函数
        }
    }

    // 禁用拷贝（避免栈数组拷贝）
    SmallVector(const SmallVector &) = delete;
    SmallVector &operator=(const SmallVector &) = delete;
    // 允许移动
    SmallVector(SmallVector &&) = default;
    SmallVector &operator=(SmallVector &&) = default;
};

// 时间测量工具
template <typename F>
uint64_t measure(F &&func)
{
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int main()
{
    const size_t MAX = 32; // 嵌入式常用小尺寸
    // 现在可以正常声明无参的SmallVector了
    SmallVector<Feature, MAX> vec;

    // 测试SmallVector（栈分配）
    auto t_small = measure([&]()
                           {
        for (size_t i = 0; i < MAX; ++i) {
            vec.emplace_back(i, (float)i/100, i%4);
        } });

    // 测试std::vector（堆分配）
    auto t_std = measure([&]()
                         {
        std::vector<Feature> vec_std;
        vec_std.reserve(MAX);
        for (size_t i = 0; i < MAX; ++i) {
            vec_std.emplace_back(i, (float)i/100, i%4);
        } });

    std::cout << "SmallVector（栈分配）耗时：" << t_small << "μs\n";
    std::cout << "std::vector（堆分配）耗时：" << t_std << "μs\n";

    // 验证内存占用
    std::cout << "SmallVector内存占用：" << sizeof(SmallVector<Feature, MAX>) << "字节\n";
    std::cout << "std::vector（空）内存占用：" << sizeof(std::vector<Feature>) << "字节\n";

    return 0;
}