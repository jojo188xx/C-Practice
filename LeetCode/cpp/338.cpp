#include <iostream>
#include <vector>
using namespace std;
vector<int> countbits(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i >> 1] + (i & 1); /// 必须加括号
    }
    return dp;
}
vector<int> countBits(int n)
{
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        res[i] = res[i & (i - 1)] + 1; // 这是一种动态规划的思路，复用前一次的1个数，
        // 「复用之前计算好的、少 1 个 1 的数的计数结果，加 1 就是当前数的计数」
    }
    return res;
}
// 常规解法（O(nlogn)）
vector<int> countBits(int n)
{
    vector<int> res(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        int cnt = 0;
        int num = i;
        while (num)
        {
            cnt += num & 1; // 统计最后一位是否为1
            num >>= 1;      // 右移一位
        }
        res[i] = cnt;
    }
    return res;
}
int main()
{
    vector<int> nums = countbits(5);
    for (int num : nums)
    {
        cout << num << " ";
        /* code */
    }
}