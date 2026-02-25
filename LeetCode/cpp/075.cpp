#include <iostream>
#include <vector>
using namespace std;
void sortcolor(vector<int> &nums)
{
    int n = nums.size();
    int left = 0, i = 0, right = n - 1;
    while (i <= right) ////
    {
        // 这题得用left这里i++，left前的数是安全检查过的，且left<=i
        if (nums[i] == 0)
        {
            swap(nums[i], nums[left]);
            left++;
            i++;
        }
        else if (nums[i] == 2)
        {
            swap(nums[i], nums[right]);
            right--; // 交换来的元素可能是0/1/2，需重新检查，i不后移
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortcolor(nums);
    // 输出排序结果：0 0 1 1 2 2
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}