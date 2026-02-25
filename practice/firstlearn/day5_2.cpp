#include <memory>
#include <iostream>
using namespace std;
class Test
{
public:
    Test(int x) : val(x) { cout << "make:" << val << endl; }
    ~Test() { cout << "end" << endl; }
    void show() { cout << "val==" << val << endl; }

private:
    int val;
};
void testptr()
{
    unique_ptr<Test> up1(new Test(10));
    up1->show();
    auto up2 = make_unique<Test>(20);
    up2->show();
    unique_ptr<Test> up3 = move(up1);
    unique_ptr<Test[]> up_arr(new Test[2]{Test(11), Test(12)});
    up_arr[0].show();
    up_arr[1].show();
}
void share()
{
    shared_ptr<Test> sp1 = make_shared<Test>(100);
    cout << "count=" << sp1.use_count() << endl;
    shared_ptr<Test> sp2 = sp1;
    cout << "count=" << sp1.use_count() << endl; // 引用的次数统计
    shared_ptr<Test> sp3;
    sp3 = sp2;
    cout << "count=" << sp1.use_count() << endl;
    sp1.reset(); // 重置 sp1，使其不再指向原来的 Test 对象；
    cout << "count=" << sp2.use_count() << endl;
    shared_ptr<Test[]> sparr(new Test[2]{Test(200), Test(300)},
                             [](Test *p)
                             { delete[] p; });
    /// lambda表达式，shared_ptr默认删除器是 delete p; 不是 delete[] p;
}
void custom_deleter()
{
    shared_ptr<Test> sp_arr(new Test[3]{Test(1), Test(2), Test(3)},
                            [](Test *p)
                            {
                                cout << " cutomdelete" << endl;
                                delete[] p;
                            });
    shared_ptr<FILE> fp(fopen("test.txt", "w"),
                        [](FILE *p)
                        {
                            cout << "close file" << endl;
                            fclose(p);
                        });
    void deltest(Test * p)
    {
        delete p;
    }
    shared_ptr<Test> sp4(new Test(4), deltest);
}

int main()
{
    // testptr();
    share();
    return 0;
}