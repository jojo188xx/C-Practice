#include <iostream>
#include <vector>
#include <climits>   // 用于INT_MAX
#include <algorithm> // 用于min函数
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    // 定义dp数组，dp[i]表示凑成金额i所需的最少硬币数
    // 初始值设为amount+1（因为最多需要amount枚1元硬币，amount+1表示"无法凑成"）
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i) //
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
// 测试用例
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "minum=" << coinChange(coins, amount) << endl; // 输出：3

    // 测试无法凑成的情况
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "fail=" << coinChange(coins2, amount2) << endl; // 输出：-1
    return 0;
}