#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    void selectsort(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int curmin = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] < nums[curmin])
                {
                    curmin = j;
                }
            }
            swap(nums[i], nums[curmin]);
        }
    }
};

int main()
{
    vector<int> nums = {100, 4, -200, 1, 3, 2};
    Solution sol;
    sol.selectsort(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}