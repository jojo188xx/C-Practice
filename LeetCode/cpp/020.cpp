#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;
class solution
{
public:
    bool isvalid(string &s) 
    {
        unordered_map<char, char> brackmap = {
            {'}', '{'},
            {']', '['},
            {')', '('}};
        stack<char> st;
        char top;
        for (char ch : s)
        {
            if (brackmap.count(ch))//检查是否是存在的索引
            {
                top = st.empty() ? '0' : st.top();///////
                if (!st.empty())
                {
                    st.pop();
                }
                if (top != brackmap[ch])//////top和ch的位置错，对索引理解不透测
                {
                    return false;
                }
            }
            else
            {
                st.push(ch);
            }
        }
        return st.empty();///
    }
};
int main()
{
    string s = "(){}[]";
    solution p1;

    bool ans = p1.isvalid(s);
    cout << ans << endl;
    return 0;
}