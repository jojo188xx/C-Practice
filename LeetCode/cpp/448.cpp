#include <iostream>
#include <vector>
using namespace std;
vector<int> findnumb(vector<int> &nums)
{ // 为了不创建新空间，抛弃原有数组的取值，单纯实现标记
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int idx = abs(nums[i]) - 1; /// abs
        if (nums[idx] > 0)
        {
            nums[idx] = -nums[idx];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            res.push_back(i + 1); ///
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1}; //[1,n]
    vector<int> ans = findnumb(nums);
    for (int num : ans)
    {
        cout << num << " ";
    }
}