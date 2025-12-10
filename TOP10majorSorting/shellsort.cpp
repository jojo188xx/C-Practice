#include <iostream>
#include <vector>
using namespace std;
void shellsort(vector<int> &nums)
{
    int n = nums.size();
    int gap = n / 2;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int j = i - gap;
            int tmp = nums[i];
            while (j >= 0 && nums[j] > tmp)
            {
                nums[j + gap] = nums[j];
                j -= gap;
            }
            nums[j + gap] = tmp;
        }
        gap /= 2;
    }
}
int main(void)
{
    vector<int> nums = {8, -4, 2, -1, 0};
    shellsort(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}