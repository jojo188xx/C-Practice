#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int loop(vector<int> &nums, int l, int r, int k)
{
    if (l == r)
        return nums[k];
    int partition = nums[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (nums[i] < partition);
        do
            j--;
        while (nums[j] > partition);
        if (i < j)
            swap(nums[i], nums[j]);
    }
    if (k <= j)
        return loop(nums, l, j, k); // k在j的左侧
    else
        return loop(nums, j + 1, r, k);
}
int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    return loop(nums, 0, n - 1, n - k);
}
// int loop(vector<int> &nums, int l, int r, int k)
// {
//     if (l >= r) // 这个条件不用改，用l>=r更稳妥，兼容所有情况，比l==r好
//         return nums[k];

//     int randIdx = rand() % (r - l + 1) + l;
//     swap(nums[l], nums[randIdx]);
//     int i = l, j = r;
//     int posval = nums[l];

//     // ============ 【修改1 重中之重】把> 和 < 改成 >= 和 <= ============
//     while (i < j)
//     {
//         while (i < j && nums[j] >= posval)
//             j--; // 右指针找 小于基准的值
//         while (i < j && nums[i] <= posval)
//             i++; // 左指针找 大于基准的值
//         if (i < j)
//             swap(nums[i], nums[j]);
//     }
//     // ============ 【修改2】基准归位 必须保留 ============
//     swap(nums[l], nums[i]);

//     // ============ 【修改3 关键】用i做判断基准，代替j，彻底杜绝递归死循环 ============
//     if (k <= i)
//         return loop(nums, l, i, k);
//     else
//         return loop(nums, i + 1, r, k);
// }

int main()
{
    srand(time(0)); // 随机种子只初始化1次 ✔️
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << findKthLargest(nums1, k1) << endl; // 必输出 5

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << findKthLargest(nums2, k2) << endl; // 必输出 4
    return 0;
}