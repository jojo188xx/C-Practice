#include <iostream>
using namespace std;
void ptr()
{
    float feat[16] = {1.0f, 2.0f};
    for (float *p = feat; p < feat + 16; ++p)
    {
        *p = *p * 2;
    }
    cout << "last one in ptr:" << feat[0] << endl;
}
void modifyPTR(int *p)
{
    *p = 100;
}

int main()
{
    int a = 10;
    int *p = &a;
    cout << "addr_a=" << p << endl;
    cout << "val-p=" << *p << endl;
    modifyPTR(&a);
    cout << "modify_a=" << a << endl;
    ptr();
    return 0;
}