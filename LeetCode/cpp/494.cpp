#include <iostream>
#include <vector>
using namespace std;
int code494(vector<int> &nums, int target)
{
    int total = 0;
    for (int num : nums)
    {
        total += num;
    }
    if (total < abs(target) || (total + target) % 2 != 0) // 这里是||，不是&&
    {
        return 0;
        // 保障sumpos，正整数和是正数%2
    } // 如何理解背包问题？？？
    int sumpos = (target + total) / 2;
    vector<int> dp(sumpos + 1, 0); /////初始化+1
    dp[0] = 1;                     ///// 凑出和为 0 的组合数是 1（选 0 个数）
    for (auto &num : nums)         // 从 nums 中选若干数，和恰好等于 sum_pos 的组合数
    {
        for (int i = sumpos; i >= num; i--) ///// 要记住>=
        {
            dp[i] += dp[i - num];
        }
    }
    return dp[sumpos];
}
int main()
{
    vector<int> nums;
    nums = {1, 1, 1, 1, 1};
    int target = 3;
    int ans = code494(nums, target);
    cout << ans << endl;
    return 0;
}