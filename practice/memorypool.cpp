#include <vector>
#include <cstdlib>
#include <iostream>
class MemoryPool
{
private:
    char *pool_;
    size_t pool_size_;
    size_t used_size_;

public:
    explicit MemoryPool(size_t size) : pool_size_(size), used_size_(0)
    {
        pool_ = static_cast<char *>(malloc(size));
        if (!pool_)
        {
            throw std::bad_alloc();
        }
        std::cout << "initalize memory:" << size << "byte\n";
    }
    ~MemoryPool()
    {
        if (pool_)
        {
            free(pool_);
            pool_ = nullptr;
            std::cout << " free pool!\n";
        }
    }
    MemoryPool(const MemoryPool &) = delete;
    MemoryPool &operator=(const MemoryPool &) = delete;
    void *allocate(size_t size)
    {
        if (used_size_ + size > pool_size_)
        {
            return nullptr;
        }
        void *ptr = pool_ + used_size_;
        used_size_ += size;
        return ptr;
    }
    void reset()
    {
        used_size_ = 0;
        std::cout << "used_size clear\n";
    }
    size_t remaining() const
    {
        return pool_size_ - used_size_;
    }
};
void test_pool()
{
    try
    {
        MemoryPool pool(1024 * 1024);
        int *feat1 = static_cast<int *>(pool.allocate(1024));
        float *feat2 = static_cast<float *>(pool.allocate(2048));
        std::cout << "remaining size:" << pool.remaining() << "byte\n";
        pool.reset();
        std::cout << "resize reamin:" << pool.remaining() << "byte\n";
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "fail to allocate" << e.what() << "\n";
    }
}
int main()
{
    test_pool();
    return 0;
}