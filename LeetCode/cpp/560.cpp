#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    int cnt = 0;
    int prefixsum = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int num : nums)
    {
        prefixsum += num;
        if (map.find(prefixsum - k) != map.end())
        {
            cnt += map[prefixsum - k]; // 前缀和找前缀和
        }
        // 更新当前前缀和的出现次数（存在则+1，不存在则设为1）,map自动创建
        map[prefixsum]++;
    }
    return cnt;
}
int main()
{
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    cout << " result= " << subarraySum(nums1, k1) << endl;
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    cout << " result= " << subarraySum(nums2, k2) << endl; // 输出 2
    return 0;
}