#include <iostream>
#include <vector>
// 无需额外头文件（std::vector 和 std::cout 是核心依赖）

// 插入排序函数（传值避免修改原数组，对应Python的nums.copy()）
std::vector<int> insertsort(std::vector<int> nums)
{
    int n = nums.size();
    // 从第二个元素开始遍历（对应Python的range(1, n)）
    for (int i = 1; i < n; ++i)
    {
        int tmp = nums[i]; // 保存当前待插入的元素
        int j = i - 1;     // 从当前元素的前一个位置开始向前比较

        // 向前遍历，将比tmp大的元素后移（和Python while逻辑完全一致）
        while (j >= 0 && nums[j] > tmp)
        {
            nums[j + 1] = nums[j]; // 元素后移
            --j;                   // 指针前移
        }
        // 将tmp插入到正确位置
        nums[j + 1] = tmp;
    }
    return nums;
}

// 主函数测试
int main()
{
    // 测试数据（和Python完全一致）
    std::vector<int> nums = {8, -4, 2, -1, 0};
    // 调用插入排序（返回新数组，原数组不变）
    std::vector<int> ans = insertsort(nums);

    // 输出排序结果
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