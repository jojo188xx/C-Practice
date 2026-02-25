#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    int prev_prev = nums[0];
    int prev = max(nums[0], nums[1]); // 注意含义，是前一个最大利润
    for (int i = 2; i < n; i++)
    {
        int cur = max(prev, prev_prev + nums[i]);
        prev_prev = prev;
        prev = cur;
    }
    return prev;
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << rob(nums) << endl;
}