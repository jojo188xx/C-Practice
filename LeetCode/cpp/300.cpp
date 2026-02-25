#include <iostream>
#include <vector>
using namespace std;
int lengthoflis(vector<int> &nums)
{
    vector<int> tails;
    for (int num : nums)
    {
        int left = 0, right = tails.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (tails[mid] < num)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        // 在 tails 数组中，第一个大于等于 num 的元素的下标。
        // 没找到就会是末位
        if (left == tails.size())
        {
            tails.push_back(num);
        }
        else
        {
            tails[left] = num;
        }
    }
    return tails.size();
}
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthoflis(nums) << endl;
    return 0;
}