#include <iostream>
#include <vector>
using namespace std;
void bk(vector<int> &nums, int index, vector<int> &current, vector<vector<int>> &res)
{
    res.push_back(current);
    for (int i = index; i < nums.size(); i++)
    {
        current.push_back(nums[i]);
        bk(nums, i + 1, current, res);
        current.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> current;
    bk(nums, 0, current, res);
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    for (auto &subset : res)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i)
        {
            if (i > 0)
                cout << ","; // 元素间加逗号（避免开头/结尾多余逗号）
            cout << subset[i];
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}