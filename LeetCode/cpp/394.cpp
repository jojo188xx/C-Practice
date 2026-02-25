#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {
        stack<pair<string, int>> stk;
        string curstr = "";
        int curnum = 0;
        for (char c : s)
        {
            if (isdigit(c))
            {
                curnum = curnum * 10 + (c - '0');
            }
            else if (c == '[')
            {
                stk.push({curstr, curnum});
                curnum = 0;
                curstr = "";
            }
            else if (c == ']')
            {
                // 嵌套情况重复次数存放在之前的栈顶里
                pair<string, int> toppair = stk.top();
                stk.pop();
                string prevstr = toppair.first; // 外层字符串
                int num = toppair.second;
                string tmp = "";
                for (int i = 0; i < num; i++)
                {
                    tmp += curstr; // 内层字符串
                }
                curstr = prevstr + tmp;
            }
            else
            {
                curstr += c;
            }
        }
        return curstr;
    }
};
// 测试代码
int main()
{
    Solution sol;
    // 测试用例1：基础嵌套
    string s1 = "3[a]2[bc]";
    cout << sol.decodeString(s1) << endl; // 输出：aaabcbc

    // 测试用例2：多层嵌套
    string s2 = "3[a2[c]]";
    cout << sol.decodeString(s2) << endl; // 输出：accaccacc

    // 测试用例3：多位数
    string s3 = "10[ab]";
    cout << sol.decodeString(s3) << endl; // 输出：abababababababababab

    return 0;
}