#include <iostream>
#include <string>
#include <memory>
using namespace std;
class InferenceOperator
{
public:
    virtual ~InferenceOperator()
    {
        cout << "infer Operator xigou" << endl;
    }
    virtual void init() = 0;
    virtual void run(const string &input_data) = 0;
    virtual string get_hardware_name() const = 0;
    void print_status() const
    {
        cout << "[" << get_hardware_name() << "]" << endl;
    }
};
class CPUinference : public InferenceOperator
{
public:
    // 构造函数，无返回类型
    CPUinference(int core_num) : core_num_(core_num)
    {
        cout << "cpu corenum=" << core_num_ << endl;
    }
    void init() override
    {
        is_init_ = true;
        cout << "cpuinit success\n"
             << endl;
    }
    void run(const string &input_data) override
    {
        if (!is_init_)
        {
            cerr << "cpu not init" << endl;
            return;
        }
        cout << "cpu inputdata=" << input_data << endl;
    }
    string get_hardware_name() const override
    {
        return "cpu";
    }
    ~CPUinference() override
    {
        cout << "cpu xigou" << endl;
    }

private:
    int core_num_;
    bool is_init_ = false;
};
