#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
int numSquares(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            // i++很大时候越界
            /// if (dp[i - j * j] != INT_MAX)
            { // 取“当前已找到的最小值”和“新尝试的凑法值”中更小的那个
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
    }
    return dp[n];
}
int main()
{
    int n = 12;
    cout << numSquares(n) << endl;
    return 0;
}