#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void nextpre(vector<int> &nums)
{
    int n = nums.size();
    int i = n - 2;
    // 找降序的起始位置，从后往前找，要加=
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }
    // 找降序中大于nums[i]的最小数交换
    if (i >= 0)
    {
        int j = n - 1;
        // 同理加=
        while (nums[j] <= nums[i])
        {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    // 逆序i+1至末尾
    reverse(nums.begin() + i + 1, nums.end());
}
int main()
{
    vector<int> nums1 = {1, 2, 3};
    nextpre(nums1);
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;
    vector<int> nums2 = {3, 1, 2};
    nextpre(nums2);
    for (int num : nums2)
    {
        cout << num << " ";
    }
    cout << endl;
}