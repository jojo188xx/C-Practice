#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int longeststring(string s)
{
    unordered_set<char> charset;
    int left = 0, maxlen = 0;
    for (int right = 0; right < s.size(); right++)
    {
        while (charset.find(s[right]) != charset.end()) /// while
        {
            charset.erase(s[left]);
            left++;
        }
        charset.insert(s[right]);
        maxlen = max(maxlen, right - left + 1); ////
    }
    return maxlen;
}
int main()
{
    cout << longeststring("abcabcbb") << endl; // 输出 3
    cout << longeststring("bbbbb") << endl;    // 输出 1
    cout << longeststring("pwwkew") << endl;   // 输出 3
    cout << longeststring("") << endl;         // 输出 0
    return 0;
}