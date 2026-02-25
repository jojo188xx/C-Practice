#include <iostream>

class Base
{
public:
    virtual ~Base() = default; // 基类必须具有虚函数
};

class Derived : public Base
{
public:
    void show()
    {
        std::cout << "Derived class method" << std::endl;
    }
};

int main()
{
    Base *ptr_Base = new Derived;
    Derived *ptr_Derived = dynamic_cast<Derived *>(ptr_Base);
    if (ptr_Derived)
    {
        ptr_Derived->show();
    }
    Derived derive_obj;
    Base &ref_base = derive_obj;
    Derived &ref_derived = dynamic_cast<Derived &>(ref_base);
    ref_derived.show();
}