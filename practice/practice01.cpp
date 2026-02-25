#include <iostream>
using namespace std;
#include <vector>

int main()
{
    vector<int> nums = {2, 3, 4};
    auto it = nums.begin();

    // 1. 基础：访问第一个元素
    cout << "第一个元素：" << *it << endl; // 输出 2

    // 2. 迭代器移动：++it 指向后一个元素
    ++it;                                  // it 现在指向 3
    cout << "移动后指向：" << *it << endl; // 输出 3

    // 3. 遍历整个vector（最常用的迭代器用法）
    cout << "\n遍历所有元素：";
    for (auto iter = nums.begin(); iter != nums.end(); ++iter)
    {
        // nums.end() 是尾后迭代器（指向最后一个元素的下一个位置，不能解引用）
        cout << *iter << " "; // 输出 2 3 4
    }
    cout << endl;

    // 4. 迭代器删除（重点：接收erase的返回值）
    cout << "\n删除元素3后：";
    it = nums.begin() + 1; // it 指向第二个元素（3）
    it = nums.erase(it);   // 删除3，返回指向4的迭代器
    for (auto iter = nums.begin(); iter != nums.end(); ++iter)
    {
        cout << *iter << " "; // 输出 2 4
    }
    cout << endl;

    return 0;
}