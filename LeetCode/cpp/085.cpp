#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // 用于max函数
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        // 边界条件：矩阵为空或第一行为空，直接返回0
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }

        int rows = matrix.size();     // 矩阵的行数
        int cols = matrix[0].size();  // 矩阵的列数
        vector<int> heights(cols, 0); // 记录每一列的连续1的高度，初始为0
        int max_area = 0;             // 最终要返回的最大矩形面积

        // 逐行遍历矩阵，构建每一行对应的直方图
        for (int i = 0; i < rows; ++i)
        {
            // 步骤1：更新当前行的高度数组heights
            for (int j = 0; j < cols; ++j)
            {
                // 如果当前位置是'1'，高度+1；否则重置为0
                if (matrix[i][j] == '1')
                {
                    heights[j]++;
                }
                else
                {
                    heights[j] = 0;
                }
            }

            // 步骤2：计算当前直方图的最大矩形面积，并更新全局最大值
            max_area = max(max_area, largestRectangleArea(heights));
        }

        return max_area;
    }

private:
    // 子函数：计算单个直方图的最大矩形面积（单调栈核心逻辑）
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st; // 单调栈，存储的是柱子的索引，保证栈内索引对应的高度单调递增
        int max_area = 0;
        int n = heights.size();

        // 技巧：在高度数组末尾加一个0，确保栈中所有元素都能被处理到
        heights.push_back(0);

        // 遍历每个柱子（包括最后新增的0）
        for (int i = 0; i < heights.size(); ++i)
        {
            // 当栈不为空，且当前柱子高度 < 栈顶柱子高度时，计算栈顶柱子的最大面积
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                // 弹出栈顶元素，作为当前要计算面积的柱子
                int top_idx = st.top();
                st.pop();
                int h = heights[top_idx]; // 当前柱子的高度

                // 计算宽度：
                // - 栈空：说明当前柱子是目前遍历到的最矮的，宽度为i
                // - 栈不空：宽度为 当前索引 - 新栈顶索引 - 1
                int w = st.empty() ? i : (i - st.top() - 1);

                // 更新最大面积
                max_area = max(max_area, h * w);
            }

            // 栈为空 或 当前柱子高度 >= 栈顶柱子高度，入栈（保持单调递增）
            st.push(i);
        }

        // 恢复原数组（可选，避免影响后续使用）
        heights.pop_back();
        return max_area;
    }
};

// 测试代码：可以直接运行
int main()
{
    // 示例输入矩阵
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    Solution sol;
    int result = sol.maximalRectangle(matrix);
    cout << "maxarea=" << result << endl; // 输出：6

    return 0;
}