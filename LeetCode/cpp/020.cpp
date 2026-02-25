#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isvalid(string s)
    {
        stack<char> st;
        // 哈希表：右括号为键，对应的左括号为值，方便快速匹配
        unordered_map<char, char> map = {{']', '['}, {')', '('}, {'}', '{'}};
        for (char ch : s)
        {
            // 情况1：是左括号，直接入栈
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                // 情况2：是右括号，【先判断栈是否为空】，空则无匹配的左括号
                if (st.empty())
                {
                    return false;
                }
                // 栈非空，取出栈顶元素并出栈
                char top = st.top();
                st.pop();
                // 匹配失败，直接返回false
                if (top != map[ch])
                {
                    return false;
                }
            }
        }
        // 遍历结束后，栈为空则全部匹配成功，否则有未闭合的左括号
        return st.empty();
    }
};
int main()
{
    string s = "(){}[]";
    Solution p1;

    bool ans = p1.isvalid(s);
    cout << ans << endl;
    return 0;
}