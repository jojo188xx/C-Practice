#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void countsort(vector<int> &nums)
{
    int minval = *min_element(nums.begin(), nums.end());
    int maxval = *max_element(nums.begin(), nums.end());
    int valrange = maxval - minval;
    vector<int> count(valrange + 1, 0);
    for (int num : nums)
    {
        count[num - minval] += 1;
    }
    int id = 0;
    for (int i = 0; i < count.size(); i++)
    {
        int val = i + minval;
        while (count[i] > 0)
        {
            nums[id++] = val;
            count[i]--;
        }
    }
}
int main(void)
{
    vector<int> nums = {8, -4, 2, -1, 0};
    countsort(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}