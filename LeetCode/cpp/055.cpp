#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canjump(vector<int> &nums)
{
    int max_reach = 0; ////
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i > max_reach) /////
        {
            return false;
        }
        max_reach = max(max_reach, nums[i] + i);
        if (max_reach >= n - 1)
        {
            return true;
        }
    }
    return true;
}
int main()
{
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "nums1: " << (canjump(nums1) ? "True" : "False") << endl; // 输出True
    cout << "nums2: " << (canjump(nums2) ? "True" : "False") << endl; // 输出False
    return 0;
}