#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> num_set;
    for (int num : nums) ////
    {
        num_set.insert(num);
    }
    int maxlen = 0;
    for (int num : num_set) /// 原先nums里有很多重复数组，改set中是没有重复的，因此更快
    {                       // 用find不用count，find更快不超过时间限制
        if (num_set.find(num - 1) == num_set.end())
        {
            int curnum = num;
            int curlen = 1;//
            while (num_set.find(curnum + 1) != num_set.end())
            {
                curnum++;
                curlen++;
            }
            maxlen = max(maxlen, curlen);
        }
    }
    return maxlen;
}
int main()
{

    // 测试用例1：常规情况
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums1) << endl; // 预期输出4

    // 测试用例2：更长的连续序列
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums2) << endl; // 预期输出9

    // 测试用例3：空数组
    vector<int> nums3 = {};
    cout << longestConsecutive(nums3) << endl; // 预期输出0

    // 测试用例4：单元素数组
    vector<int> nums4 = {5};
    cout << longestConsecutive(nums4) << endl; // 预期输出1

    return 0;
}