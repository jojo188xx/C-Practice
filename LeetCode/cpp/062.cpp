#include <iostream>
#include <vector>
using namespace std;
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1)); ////理解麻烦，m行n列，直接初始全为1
    /// m和m+1，在初始化和边界处理上完全不同
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1]; // 其实序列是0、1、所以从1开始，最后-1
}
int main()
{
    cout << "m=3, n=7 " << uniquePaths(3, 7) << endl; // 28
    return 0;
}