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
    if (total < abs(target) || (total + target) % 2 != 0)
    {
        return 0;
    }
    int sumpos = (target + total) / 2;
    vector<int> dp(sumpos + 1, 0);
    dp[0] = 1;
    for (auto &num : nums)
    {
        for (int i = sumpos; i >= num; i--) // 根本记不起来了
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