#include <iostream>
#include <vector>
using namespace std;
vector<int> productself(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, 1);
    int pre = 1;
    for (int i = 0; i < n; i++)
    {
        res[i] = pre;
        pre *= nums[i];
    }
    int suff = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        res[i] *= suff;
        suff *= nums[i];
    }
    return res;
}
// 测试主函数（测试用例全覆盖）
int main()
{
    // 测试用例1：常规正整数
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> ans1 = productself(nums1);
    cout << "测试用例1结果: ";
    for (int num : ans1)
        cout << num << " "; // 输出: 24 12 8 6
    cout << endl;

    // 测试用例2：包含0和负数
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> ans2 = productself(nums2);
    cout << "测试用例2结果: ";
    for (int num : ans2)
        cout << num << " "; // 输出: 0 0 9 0 0
    cout << endl;

    return 0;
}