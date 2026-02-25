#include <iostream>
#include <vector>
using namespace std;
int numcount(vector<int> &nums)
{
    // 任何数和自身异或，结果为 0（例如：a ^ a = 0）
    // 任何数和 0 异或，结果为自身（例如：a ^ 0 = a）
    // 异或运算满足交换律和结合律（例如：a^b^c = a^c^b）
    int result = 0;
    for (int num : nums)
    {
        result ^= num;
    }
    return result;
}
int main()
{
    vector<int> nums = {4, 2, 3, 4, 3, 1, 2};
    cout << numcount(nums);
    return 0;
}
