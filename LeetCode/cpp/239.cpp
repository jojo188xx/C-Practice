#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> res;
        // 双端队列，存储元素下标，队列内元素对应的值单调递减
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            // 1. 移除队列中超出窗口范围的元素（下标 <= i-k）
            while (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // 2. 维护队列单调性：移除尾部比当前元素小的元素
            // 这些元素不可能成为后续窗口的最大值
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            // 3. 加入当前元素下标
            dq.push_back(i);

            // 4. 从第k-1个元素开始，收集每个窗口的最大值
            if (i >= k - 1)
            {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};

// 辅助函数：打印vector
void printVector(const vector<int> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i != vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    // 测试用例1：经典示例
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    Solution sol;
    vector<int> res1 = sol.maxSlidingWindow(nums1, k1);
    cout << "测试用例1结果：";
    printVector(res1); // 预期输出：[3, 3, 5, 5, 6, 7]

    // 测试用例2：边界情况（k=1）
    vector<int> nums2 = {7, 2, 4};
    int k2 = 1;
    vector<int> res2 = sol.maxSlidingWindow(nums2, k2);
    cout << "测试用例2结果：";
    printVector(res2); // 预期输出：[7, 2, 4]

    // 测试用例3：边界情况（数组长度等于k）
    vector<int> nums3 = {1, 2, 3};
    int k3 = 3;
    vector<int> res3 = sol.maxSlidingWindow(nums3, k3);
    cout << "测试用例3结果：";
    printVector(res3); // 预期输出：[3]

    return 0;
}