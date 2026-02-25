#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int res = 0;

        while (left < right)
        {
            // 为什么要判断height[left] < height[right]？
            // 这个判断的核心结论是：谁小，就处理谁的位置，并且移动谁的指针。
            // 原因很简单：左右两侧的最大高度的较小值，由「当前左右指针指向的高度」中较小的一侧决定，且这一侧的max值是确定的、有效的，可以直接用来计算雨水量。
            if (height[left] < height[right])
            {
                height[left] >= left_max ? left_max = height[left] : res += left_max - height[left];
                left++;
            }
            else
            {
                height[right] >= right_max ? right_max = height[right] : res += right_max - height[right];
                right--;
            }
        }
        return res;
    }
};

// 主函数：测试用例验证
int main()
{
    Solution sol;
    // 测试用例1：经典用例，预期输出6
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "测试用例1结果：" << sol.trap(height1) << endl;

    // 测试用例2：预期输出9
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "测试用例2结果：" << sol.trap(height2) << endl;

    // 测试用例3：空数组/单元素，预期输出0
    vector<int> height3 = {};
    vector<int> height4 = {5};
    cout << "测试用例3结果：" << sol.trap(height3) << endl;
    cout << "测试用例4结果：" << sol.trap(height4) << endl;

    return 0;
}