#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution
{
private:
    // 分区函数：去掉随机选择，直接用最右边作为 pivot
    int partition(vector<int> &nums, int l, int r)
    {
        // 直接用最后一个元素当 pivot，不随机！
        int pivot = nums[r];
        int i = l;

        for (int j = l; j < r; ++j)
        {
            if (nums[j] > pivot)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }

    int quickselect(vector<int> &nums, int l, int r, int k)
    {
        if (l == r)
            return nums[l];

        int pos = partition(nums, l, r);

        if (pos == k)
        {
            return nums[pos];
        }
        else if (pos > k)
        {
            return quickselect(nums, l, pos - 1, k);
        }
        else
        {
            return quickselect(nums, pos + 1, r, k);
        }
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // 这里删掉了 srand(time(0))
        return quickselect(nums, 0, nums.size() - 1, k - 1);
    }
};
int main()
{
    Solution sol;
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << sol.findKthLargest(nums1, k1) << endl; // 必输出 5

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << sol.findKthLargest(nums2, k2) << endl; // 必输出 4
    return 0;
}