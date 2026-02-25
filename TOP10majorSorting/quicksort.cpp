#include <vector>
#include <iostream>
using namespace std;
vector<int> nums;
int partition(vector<int> &nums, int l, int r)
{
    int posval = nums[r];
    int i = l - 1;
    for (int j = l; j < r; j++) /// 区间是range(l,r)
    {
        if (nums[j] < posval)
        {
            i += 1;
            swap(nums[j], nums[i]);
        }
    }
    swap(nums[i + 1], nums[r]); /// 处理最后的基准值，传递下去
    return i + 1;
}
void quicksort(vector<int> &nums, int l, int r)
{

    if (l < r)
    {
        int pos = partition(nums, l, r);
        quicksort(nums, l, pos - 1);
        quicksort(nums, pos + 1, r);
    }
}
int main(void)
{
    nums = {8, -4, 2, -1, 0};
    int l = 0, r = nums.size() - 1;
    quicksort(nums, l, r);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}