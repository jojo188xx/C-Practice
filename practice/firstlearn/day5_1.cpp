#include <iostream>
#include <memory>
using namespace std;
class A;
class B;

class A
{
public:
    weak_ptr<B> b_ptr;
    // shared_ptr<B> b_ptr;
    ~A() { cout << "A析构" << endl; }
};

class B
{
public:
    weak_ptr<A> a_ptr;
    // shared_ptr<A> a_ptr;
    ~B() { cout << "B析构" << endl; }
};

void test_cycle()
{
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->b_ptr = b; // A引用B
    b->a_ptr = a; // B引用A
    // 函数结束后，a和b的计数都是2，析构时计数减为1，无法释放内存！
}

int main()
{
    test_cycle();
    cout << "函数结束" << endl; // 无A/B析构输出，内存泄漏
    return 0;
}