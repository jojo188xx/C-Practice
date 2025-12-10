#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            int it = target - nums[i];
            if (map.find(it) != map.end())
            {
                return {map[it], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    // 测试用例
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    // 输出结果
    cout << "id:" << result[0] << " and " << result[1] << endl;
    // 预期输出：下标为：0 和 1

    return 0;
}