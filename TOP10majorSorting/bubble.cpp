#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;
bool swapped;
void bubble(vector<int> &nums)
{
    int n = nums.size();
    for (int j = 0; j < n - 1; j++) // 控制轮数
    {
        for (int i = 0; i < n - j - 1; i++) // n-j-1
        {
            if (nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
}
int main(void)
{
    nums = {8, -4, 2, -1, 0};
    bubble(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}