#include <iostream>
#include <vector>
#include <algorithm> // 用于std::max_element
#include <climits>   // 用于处理极值（可选）

// 基数排序函数（仅支持非负整数，与原Python逻辑一致）
std::vector<int> radixsort(std::vector<int> nums)
{
    // 处理空数组情况
    if (nums.empty())
    {
        return {};
    }
    int maxVal = *std::max_element(nums.begin(), nums.end());/////
    int digit = 1;
    while (maxVal / digit > 0)
    {
        std::vector<std::vector<int>> buckets(10);

        // 将元素分配到对应桶中
        for (int num : nums)
        {
            // 计算当前位的数字（个位/十位/百位...）
            int cur = (num / digit) % 10;
            buckets[cur].push_back(num);
        }
        nums.clear(); 
        for (auto &buk : buckets)
        {
            nums.insert(nums.end(), buk.begin(), buk.end());/////
        }

        // 处理下一位（十位→百位→...）
        digit *= 10;
    }

    return nums;
}

// 主函数测试
int main()
{
    // 测试数据（与Python完全一致）
    std::vector<int> nums = {56, 7, 3, 9, 5, 0, 77};
    // 调用基数排序
    std::vector<int> ans = radixsort(nums);

    // 输出排序结果
    std::cout << "排序结果：";
    for (int num : ans)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 验证原数组未被修改
    std::cout << "原数组：";
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}