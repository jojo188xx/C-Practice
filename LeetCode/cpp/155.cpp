#include <iostream>
#include <stack>
using namespace std;
class MinStack
{
private:
    stack<int> main_stack;
    stack<int> min_stack;

public:
    MinStack() { min_stack.push(INT_MAX); }
    void push(int val)
    {
        main_stack.push(val);
        min_stack.push(min(min_stack.top(), val));
    }
    void pop()
    {
        main_stack.pop();
        min_stack.pop();
    }
    int top()
    {
        return main_stack.top();
    }
    int getMin()
    {
        return min_stack.top();
    }
};
int main()
{
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout << "current min=" << st.getMin() << endl;
    st.pop();
    cout << "curr top=" << st.top() << endl;
    cout << "curr min=" << st.getMin() << endl;
    return 0;
}