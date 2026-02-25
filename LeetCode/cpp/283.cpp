#include <iostream>
#include <vector>
using namespace std;
void movezero(vector<int> &nums)
{
    int left = 0;
    int n = nums.size();
    for (int right = 0; right < n; right++)
    {
        if (nums[right] != 0)
        {
            swap(nums[right], nums[left]);
            left++;
        }
    }
}
int main()
{
    vector<int> nums = {0, 5, 4, 0, -6, 4};
    movezero(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
}