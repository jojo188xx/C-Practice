#include <vector>
#include <climits> // 包含 INT_MAX/INT_MIN 常量
using namespace std;
class Solution
{
public:
    int findarry(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return 0;
        }
        int maxval = nums[0];
        int right = -1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < maxval)
            {
                right = i;
                // 当前元素比左侧最大值小，属于无序区，更新右边界
            }
            else
            {
                maxval = nums[i];
            }
        }
        if (right == -1)
        {
            return 0;
        }
        int minval = nums[n - 1];
        int left = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > minval)
            {
                left = i;
            }
            else
            {
                minval = nums[i];
            }
        }
        return right - left + 1;
    }
};
// 测试代码示例
#include <iostream>
int main()
{
    Solution s;
    // 测试用例1：[2,6,4,8,10,9,15] → 输出5
    vector<int> nums1 = {2, 6, 4, 8, 10, 9, 15};
    cout << s.findarry(nums1) << endl;

    // 测试用例2：[1,2,3,4] → 输出0
    vector<int> nums2 = {1, 2, 3, 4};
    cout << s.findarry(nums2) << endl;

    return 0;
}