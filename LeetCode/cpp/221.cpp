#include <iostream>
#include <vector>
#include <algorithm> // min/max 必备头文件
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSide = 0;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // 初始化第一行
        for (int j = 0; j < cols; j++)
        {
            dp[0][j] = matrix[0][j] - '0';
            maxSide = max(maxSide, dp[0][j]);
        }
        // 初始化第一列
        for (int i = 0; i < rows; i++)
        {
            // if(matrix[i][0]=='1')dp[i][0]=1;本质就是赋值1
            dp[i][0] = matrix[i][0] - '0';
            maxSide = max(maxSide, dp[i][0]);
        }

        // 起始位置是1，1，第一行和第一列的边长必须先验输入
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide; // 边长平方 = 面积
    }
};

// ============ 完整的main主函数 ============
int main()
{
    // 测试用例1：你截图里的经典输入
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    Solution sol;
    int ans = sol.maximalSquare(matrix);
    cout << "test1 = " << ans << endl; // 输出 4 (边长2)

    // 测试用例2：空矩阵
    vector<vector<char>> matrix2;
    cout << "null  = " << sol.maximalSquare(matrix2) << endl; // 输出 0

    // 测试用例3：只有1个元素的矩阵
    vector<vector<char>> matrix3 = {{'1'}};
    cout << "11 = " << sol.maximalSquare(matrix3) << endl; // 输出 1

    return 0;
}