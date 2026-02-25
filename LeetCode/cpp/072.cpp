#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int mindistance(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    // dp[i][j] 表示：将 word1 的前 i 个字符（word1[0..i-1]
    // ）转换为 word2 的前 j 个字符（word2[0..j-1]）所需的最少操作次数。
    // 这题要涵盖m和n位置上的字母
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; i++)
    {
        dp[i][0] = i; // word1 前 i 个字符转换为 “空串”，需要删除 i 次
    }
    for (int j = 1; j < n + 1; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            { // dp[i-1][j-1]+1：替换（改word1[i-1]为word2[j-1]）
                // dp[i-1][j]+1：删除（删word1[i-1]，匹配前i-1和j）
                // dp[i][j-1]+1：插入（给word1加word2[j-1]，匹配前i和j-1）
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1; ///
                // min{}
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string word1 = "horse";
    string word2 = "ros";
    cout << "min:" << mindistance(word1, word2) << endl; // 输出3

    // 额外测试：空串场景
    string word3 = "";
    string word4 = "a";
    cout << "null:" << mindistance(word3, word4) << endl; // 输出1
    return 0;
}