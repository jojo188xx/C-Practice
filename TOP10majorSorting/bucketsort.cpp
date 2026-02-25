#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketsort(vector<int> &nums) // 必须是引用传递，否则会用拷贝数组替代
{

    int maxval = *max_element(nums.begin(), nums.end());
    int minval = *min_element(nums.begin(), nums.end());
    int cnt = (maxval - minval) / 10 + 1; /// 还是漏1，
    vector<vector<int>> bucket(cnt);

    for (int num : nums)
    {
        int tmp = (num - minval) / 10; // 是找索引，一个桶存10个数的范围
        bucket[tmp].push_back(num);
    }
    nums.clear();
    for (auto &buck : bucket)
    {
        sort(buck.begin(), buck.end());                    // 直接调用sort
        nums.insert(nums.end(), buck.begin(), buck.end()); ////
    }
}
int main()
{
    vector<int> nums;
    nums = {8, -4, 2, -1, 0};
    bucketsort(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}