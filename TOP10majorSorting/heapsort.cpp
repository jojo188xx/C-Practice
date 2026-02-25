#include <iostream>
#include <vector>
#include <algorithm> // 可选：若需要辅助函数
#include <utility>   // 用于std::swap

// 堆排序核心类/函数封装
class HeapSort
{
public:
    void heapify(std::vector<int> &arr, int n, int i)
    {
        int largest = i;       // 初始化最大值为根节点
        int left = 2 * i + 1;  // 左子节点索引
        int right = 2 * i + 2; // 右子节点索引

        // 如果左子节点比根节点大，更新最大值索引
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        // 如果右子节点比当前最大值大，更新最大值索引
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        // 如果最大值不是根节点，交换根节点和最大值节点，并递归调整受影响的子树
        if (largest != i)
        {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest); // 递归调整交换后的子树
        }
    }

    // 堆排序主函数
    void heapSort(std::vector<int> &arr)
    {
        int n = arr.size();

        // 第一步：构建大顶堆（从最后一个非叶子节点开始向前调整）
        // 最后一个非叶子节点的索引：n/2 - 1
        for (int i = n / 2 - 1; i >= 0; --i)
        {
            heapify(arr, n, i);
        }

        // 第二步：逐个取出堆顶元素（最大值），放到数组末尾
        for (int i = n - 1; i > 0; --i)
        {
            std::swap(arr[0], arr[i]); // 堆顶（最大值）与当前未排序部分末尾交换
            heapify(arr, i, 0);        // 调整剩余 i 个元素为大顶堆
        }
    }
};

// 测试主函数
int main()
{
    // 测试数据（对应Python的nums=[8,-4,2,-1,0]）
    std::vector<int> nums = {1, 5, -8, 0, 7};
    // 调用堆排序（返回新数组，不修改原数组）
    HeapSort hp;
    hp.heapSort(nums);
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}