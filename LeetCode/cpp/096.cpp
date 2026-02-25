#include <vector>
#include <iostream>
using namespace std;
int numTrees(int n)
{
    // 定义 dp[i]：由 i 个互不相同的节点，能构成的不同二叉搜索树的总数
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            dp[i] += dp[k - 1] * dp[i - k];
        }
    }
    return dp[n];
}
int main()
{
    cout << numTrees(3) << endl;
    return 0;
}