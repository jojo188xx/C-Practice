#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maxproduc(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }
    int curmax = nums[0];
    int curmin = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int num = nums[i];
        int temp = curmax;
        curmax = max({num, num * temp, num * curmin});
        curmin = min({num, num * temp, num * curmin});
        res = max(res, curmax);
    }
    return res;
}
int main()
{
    vector<int> nums1 = {2, 3, -2, 4};
    cout << maxproduc(nums1) << endl;
    vector<int> nums2 = {0, 2};
    cout << maxproduc(nums2) << endl;
    return 0;
}