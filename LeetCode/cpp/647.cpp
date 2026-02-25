#include <iostream>
#include <string>
using namespace std;
int countingstring(string s)
{
    int n = s.size();
    int counting = 0;
    auto expand = [&](int left, int right) -> int
    {
        int cnt = 0;
        while (left >= 0 && right < n && s[left] == s[right]) /// 整体加减，中心扩散两边
        {
            cnt++;
            left--;
            right++;
        }
        return cnt;
    };
    for (int i = 0; i < n; i++)
    {
        counting += expand(i, i);
        counting += expand(i, i + 1);
    }
    return counting;
}
int main()
{
    string s = "abc";
    cout << countingstring(s) << endl;
    return 0;
}