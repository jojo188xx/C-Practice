#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    // 一维：柱状图中最大的矩形（单调栈解法）
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st; // 单调递增栈，保存柱子索引
        st.push(-1);   // 哨兵，方便计算宽度
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i < n; ++i)
        {
            // 当栈顶不是哨兵，且当前高度 <= 栈顶高度，弹出栈顶计算面积
            while (st.top() != -1 && heights[i] <= heights[st.top()])
            {
                int top_idx = st.top();
                st.pop();
                int height = heights[top_idx];
                int width = i - st.top() - 1; // 宽度 = 当前索引 - 新栈顶索引 - 1
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }

        // 处理栈中剩余的递增序列
        while (st.top() != -1)
        {
            int top_idx = st.top();
            st.pop();
            int height = heights[top_idx];
            int width = n - st.top() - 1;
            max_area = max(max_area, height * width);
        }
        return max_area;
    }

    // 二维：最大矩形
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int max_area = 0;

        for (int i = 0; i < rows; ++i)
        {
            // 更新当前行的高度数组
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    heights[j] += 1;
                }
                else
                {
                    heights[j] = 0;
                }
            }
            // 计算当前行柱状图的最大矩形，更新全局最大值
            max_area = max(max_area, largestRectangleArea(heights));
        }
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