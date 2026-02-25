#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
bool wordbreak(string s, vector<string> &wordDict)
{
    unordered_set<string> wordset;
    for (const string &word : wordDict)
    {
        wordset.insert(word);
    }
    int n = s.size();
    vector<bool> dp(n + 1, false); // 长度是 n+1，索引 0~n
    dp[0] = true;
    // n+1,i=0也可以的，一定要明白j在前，i在后
    for (int i = 1; i < n + 1; i++)
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && wordset.count(s.substr(j, i - j)))
            { // 画一个区间，0-j-i，j是true，因此i-j也是true的话那i就是true
                dp[i] = true;
                break;
            }
        }

    return dp[n];
}
// 测试代码
int main()
{
    // 测试用例1：常规合法情况
    string s1 = "leetcode";
    vector<string> dict1 = {"leet", "code"};
    cout << (wordbreak(s1, dict1) ? "true" : "false") << endl; // 预期输出true

    // 测试用例2：多段拆分
    string s2 = "applepenapple";
    vector<string> dict2 = {"apple", "pen"};
    cout << (wordbreak(s2, dict2) ? "true" : "false") << endl; // 预期输出true

    // 测试用例3：非法情况
    string s3 = "catsandog";
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << (wordbreak(s3, dict3) ? "true" : "false") << endl; // 预期输出false

    // 测试用例4：空字符串（边界情况）
    string s4 = "";
    vector<string> dict4 = {"a"};
    cout << (wordbreak(s4, dict4) ? "true" : "false") << endl; // 预期输出true

    return 0;
}