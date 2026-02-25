#include <iostream>
#include <vector>
#include <algorithm> // 用于max函数
using namespace std;
int maxProfit(vector<int> &prices)
{
    if (prices.empty())
        return 0;
    int n = prices.size();
    int hold = -prices[0];
    int freeze = 0;
    int not_freeze = 0;
    for (int i = 1; i < n; i++)
    {
        // 第 i 天结束时，手里持有股票（可能是之前买的，也可能是今天刚买的）
        // 第 i 天结束时，手里没有股票，且处于冷冻期（因为今天刚卖出股票）
        // 第 i 天结束时，手里没有股票，且不处于冷冻期（可以随时买）
        int new_hold = max(hold, not_freeze - prices[i]);
        int new_freeze = hold + prices[i];
        int new_not_freeze = max(not_freeze, freeze);
        hold = new_hold;
        freeze = new_freeze;
        not_freeze = new_not_freeze;
    }
    return max(freeze, not_freeze);
} // 测试用例
int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << maxProfit(prices) << endl; // 输出：3
    return 0;
}