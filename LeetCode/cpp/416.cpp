#include <iostream>
#include <vector>
// #include <numeric> // 用于 accumulate 函数
using namespace std;
bool canpt(vector<int> &nums)
{
    int total = 0;
    for (int num : nums)
    {
        total += num;
    }
    if (total % 2 == 1)
    {
        return false;
    }
    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : nums)
    {
        // 「加入这个数字后，能凑出哪些新的和」
        for (int i = target; i >= num; i--)
        {
            if (dp[i - num])
            {
                // 「能凑出和为 i - num」，那么「加上当前数字 num，就能凑出和为 i」
                dp[i] = true;
            }
        }
    }
    return dp[target];
}
// 测试用例
int main()
{
    vector<int> nums1 = {1, 5, 11, 5};
    cout << (canpt(nums1) ? "True" : "False") << endl; // 输出 True

    vector<int> nums2 = {1, 2, 3, 5};
    cout << (canpt(nums2) ? "True" : "False") << endl; // 输出 False

    return 0;
}