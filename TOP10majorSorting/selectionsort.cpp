#include <iostream>
#include <vector>
using namespace std;
void selectionsort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_id = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[min_id])
            {
                min_id = j;
            }
        }
        swap(nums[i], nums[min_id]);
    }
}
int main(void)
{
    vector<int> nums = {8, -4, 2, -1, 0};
    selectionsort(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}