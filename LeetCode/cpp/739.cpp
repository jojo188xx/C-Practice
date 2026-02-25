#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    // 初始化结果数组，所有元素默认值为 0
    vector<int> answer(n, 0);
    // 栈中存储的是温度数组的索引，保持索引对应的温度单调递减
    stack<int> stk;

    for (int i = 0; i < n; ++i)
    {
        // 当前温度大于栈顶索引对应的温度时，计算天数差
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()])
        {
            int prev_index = stk.top();
            stk.pop();
            answer[prev_index] = i - prev_index;
        }
        // 否则将当前索引入栈，等待后续匹配
        stk.push(i);
    }

    return answer;
}

// 测试函数
int main()
{
    // 测试示例1
    vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res1 = dailyTemperatures(temps1);
    cout << "示例1结果: ";
    for (int num : res1)
    {
        cout << num << " ";
    }
    cout << endl; // 输出: 1 1 4 2 1 1 0 0

    // 测试示例2
    vector<int> temps2 = {30, 40, 50, 60};
    vector<int> res2 = dailyTemperatures(temps2);
    cout << "示例2结果: ";
    for (int num : res2)
    {
        cout << num << " ";
    }
    cout << endl; // 输出: 1 1 1 0

    return 0;
}