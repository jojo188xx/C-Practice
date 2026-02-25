#include <iostream>
#include <vector>
#include <algorithm> // 用于max函数
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        // 步骤1：预处理，首尾添加虚拟气球1
        int n = nums.size();
        vector<int> val(n + 2);  // 新数组，长度为原长度+2
        val[0] = val[n + 1] = 1; // 首尾设为1
        for (int i = 1; i <= n; ++i)
        {
            val[i] = nums[i - 1]; // 原数组元素填充到中间
        }

        // 步骤2：初始化DP数组，dp[i][j]表示区间(i,j)的最大硬币数
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // 步骤3：按区间长度从小到大遍历（长度从2开始，因为(i,j)至少隔1个元素）
        for (int len = 2; len <= n + 1; ++len) // i-j差值最大n+1
        {                                      // len是j - i的差值，比如len=2时i和j之间有1个元素
            // 枚举区间左端点i
            for (int i = 0; i + len <= n + 1; ++i) // n+1就是最后的下标位置了
            {
                int j = i + len; // 区间右端点
                // 枚举区间内最后戳破的气球k（i < k < j）
                for (int k = i + 1; k < j; ++k)
                {
                    // 状态转移：拆分为(i,k) + (k,j) + 戳k的硬币
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + val[i] * val[k] * val[j]);
                }
            }
        }

        // 最终结果：区间(0, n+1)包含所有原气球
        return dp[0][n + 1];
    }
};

// 测试用例
int main()
{
    Solution sol;
    vector<int> nums1 = {3, 1, 5, 8};
    cout << "测试用例1结果：" << sol.maxCoins(nums1) << endl; // 预期输出167

    vector<int> nums2 = {1, 5};
    cout << "测试用例2结果：" << sol.maxCoins(nums2) << endl; // 预期输出10

    return 0;
}