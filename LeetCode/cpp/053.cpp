#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxsub(vector<int> &nums)
{
    int maxnum = nums[0];
    int cursum = 0; /// 一定记得初始化，sum=0
    for (int num : nums)
    {
        cursum = max(num, cursum + num);
        maxnum = max(maxnum, cursum);
    }
    return maxnum;
}
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxsub(nums) << endl;
}