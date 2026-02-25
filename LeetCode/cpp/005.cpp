#include <iostream>
#include <string>
#include <utility> //pair
using namespace std;
pair<int, int> expand(const string &s, int l, int r)
{
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
        l--;
        r++;
    }
    return {l + 1, r - 1};
}
string longeststring(string s)
{
    if (s.empty())
        return "";
    int start = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++)
    {
        auto [l1, r1] = expand(s, i, i);
        auto [l2, r2] = expand(s, i, i + 1);
        if (r1 - l1 > end - start)
        {
            start = l1;
            end = r1;
        }
        if (r2 - l2 > end - start)
        {
            start = l2;
            end = r2;
        }
    }
    return s.substr(start, end - start + 1);
}
// 测试用例
int main()
{
    cout << longeststring("babad") << endl; // 输出"bab"或"aba"
    cout << longeststring("cbbd") << endl;  // 输出"bb"
    cout << longeststring("a") << endl;     // 输出"a"
    cout << longeststring("") << endl;      // 输出空字符串
    return 0;
}