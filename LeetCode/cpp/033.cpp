#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] >= nums[left])
        // 1. 加 =：覆盖 nums[mid] == nums[left] 的场景，判断左右分段
        {                                                   // target is centre
            if (nums[left] <= target && target < nums[mid]) // 2. 加 =：覆盖 target == nums[left] 的场景
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[right]) // 3. 保留 =：覆盖 target == nums[right] 的场景
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    // 测试用例1：找0，预期返回4
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "nums1 target=" << target1 << ":" << search(nums1, target1) << endl;
}