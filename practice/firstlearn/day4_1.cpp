#include <iostream>
#include <string>
using namespace std;
class BaseHardware
{
public: // 基类的通用实现
    virtual void init() = 0;
    virtual int read() = 0;
    virtual void log(const string &msg)
    {
        cout << "log:" << msg << endl;
    }
    virtual ~BaseHardware()
    {
        cout << "basehare xigou" << endl;
    }
};
class SensorA : public BaseHardware
{
public:
    void init() override
    {
        cout << "init senorA " << endl;
        this->status = true; // 明确赋值给类的成员变量（正确）
    }
    int read() override
    {
        log("sensorA reading");
        return rand() % 50;
    }
    // 子类的重写指定某功能
    void log(const string &msg) override
    {
        cout << "log SensorA" << msg << endl;
    }
    // 析构的重写最特殊，无论函数名称是什么，都能重写
    ~SensorA() override
    {
        cout << "xigou sensora" << endl;
    }

private:
    bool status = false;
};
class SensorB : public BaseHardware
{
public:
    void init() override
    {
        cout << "init sensorB\n"
             << endl;
        this->status = true;
    }
    int read() override
    {
        log("log sensorB");
        return rand() % 5000;
    }
    ~SensorB() override
    {
        cout << "sensorB release\n"
             << endl;
    }

private:
    bool status = false;
};
void manager(BaseHardware *hw)
{
    hw->init();
    int data = hw->read();
    hw->log("read data:" + to_string(data));
}
int main()
{
    BaseHardware *hw1 = new SensorA();
    BaseHardware *hw2 = new SensorB();
    manager(hw1);
    manager(hw2);
    delete (hw1);
    delete (hw2);
    return 0;
}