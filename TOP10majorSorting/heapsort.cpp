#include <iostream>
#include <vector>
#include <algorithm> // 可选：若需要辅助函数
#include <utility>   // 用于std::swap

// 堆排序核心类/函数封装
class HeapSort
{
public:
    // 堆排序入口函数
    static std::vector<int> heapsort(std::vector<int> nums)
    { // 传值避免修改原数组（对应Python的copy）
        int n = nums.size();
        // 构建最大堆
        makeheap(nums, n);
        // 逐个提取堆顶元素
        for (int i = n - 1; i > 0; --i) // 一直忘记
        {
            // 将堆顶（最大值）交换到当前未排序区间末尾
            std::swap(nums[0], nums[i]);
            // 对剩余未排序区间重新构建堆
            makeheap(nums, i);
        }
        return nums;
    }

private:
    // 构建堆（初始化堆结构）
    static void makeheap(std::vector<int> &nums, int n)
    {
        // 从最后一个非叶子节点向前遍历，调整堆结构
        for (int i = n / 2 - 1; i >= 0; --i)
        {
            heapify(nums, n, i);
        }
    }

    // 堆化：调整以i为根的子树为最大堆
    static void heapify(std::vector<int> &nums, int n, int i)
    {
        int largest = i;       // 初始化最大值为根节点
        int left = 2 * i + 1;  // 左子节点索引
        int right = 2 * i + 2; // 右子节点索引

        // 比较左子节点与当前最大值
        if (left < n && nums[left] > nums[largest])
        {
            largest = left;
        }
        // 比较右子节点与当前最大值
        if (right < n && nums[right] > nums[largest])
        {
            largest = right;
        }

        // 如果最大值不是根节点，交换并递归调整受影响的子树
        if (largest != i)
        {
            std::swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
};

// 测试主函数
int main()
{
    // 测试数据（对应Python的nums=[8,-4,2,-1,0]）
    std::vector<int> nums = {8, -4, 2, -1, 0};
    // 调用堆排序（返回新数组，不修改原数组）
    std::vector<int> ans = HeapSort::heapsort(nums);

    // 输出结果
    std::cout << "排序结果：";
    for (int num : ans)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 验证原数组未被修改（对应Python的nums.copy()）
    std::cout << "原数组：";
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}