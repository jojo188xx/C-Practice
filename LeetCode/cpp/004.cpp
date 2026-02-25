#include <iostream>
#include <vector>
#include <algorithm> // 用于min函数

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int totalLength = m + n;

        // 总长度为奇数，直接找第 (totalLength+1)/2 小的数
        if (totalLength % 2 == 1)
        {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        // 总长度为偶数，找第 totalLength/2 和 totalLength/2+1 小的数的平均值
        else
        {
            return (getKthElement(nums1, nums2, totalLength / 2) +
                    getKthElement(nums1, nums2, totalLength / 2 + 1)) /
                   2.0;
        }
    }

private:
    // 核心函数：找到两个有序数组中第 k 小的元素
    int getKthElement(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int index1 = 0, index2 = 0; // 两个数组的起始指针
        int m = nums1.size(), n = nums2.size();

        while (true)
        {
            // 边界情况1：nums1 已经遍历完，直接返回 nums2 的第 k 个元素
            if (index1 == m)
            {
                return nums2[index2 + k - 1];
            }
            // 边界情况2：nums2 已经遍历完，直接返回 nums1 的第 k 个元素
            if (index2 == n)
            {
                return nums1[index1 + k - 1];
            }
            // 边界情况3：k=1，直接返回两个数组当前指针位置的较小值
            if (k == 1)
            {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况：计算要比较的位置（防止越界）
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];

            // 排除不可能包含第 k 小元素的部分，缩小 k 的范围
            if (pivot1 <= pivot2)
            {
                k -= (newIndex1 - index1 + 1); // 排除 nums1 中 index1 到 newIndex1 的元素
                index1 = newIndex1 + 1;        // 移动 nums1 指针
            }
            else
            {
                k -= (newIndex2 - index2 + 1); // 排除 nums2 中 index2 到 newIndex2 的元素
                index2 = newIndex2 + 1;        // 移动 nums2 指针
            }
        }
    }
};

// 测试代码
int main()
{
    // 示例1：奇数长度
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution sol;
    cout << "1= " << sol.findMedianSortedArrays(nums1, nums2) << endl; // 输出 2.0

    // 示例2：偶数长度
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "2=" << sol.findMedianSortedArrays(nums3, nums4) << endl; // 输出 2.5

    return 0;
}