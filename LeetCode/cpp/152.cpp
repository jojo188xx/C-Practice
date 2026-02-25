#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    // 初始化：第一个元素既是当前最大也是当前最小
    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        int current = nums[i];
        // 保存当前的max_so_far，因为更新min_so_far时还会用到
        int temp_max = max_so_far;
        // 同时更新最大和最小乘积
        max_so_far = max({current, temp_max * current, min_so_far * current});
        min_so_far = min({current, temp_max * current, min_so_far * current});
        // 更新全局结果
        result = max(result, max_so_far);
    }
    return result;
}

// 测试用例
int main()
{
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProduct(nums) << endl; // 输出 6
    return 0;
}