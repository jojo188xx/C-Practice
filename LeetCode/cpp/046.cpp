#include <iostream>
#include <vector>
using namespace std;
void bk(vector<int> &nums, vector<vector<int>> &res, vector<int> &path, vector<bool> used)
{
    if (path.size() == nums.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            path.push_back(nums[i]);
            bk(nums, res, path, used);
            path.pop_back();
            used[i] = false;
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(nums.size(), false); /// 初始化false
    bk(nums, res, path, used);
    return res;
}
int main()
{

    vector<int> nums = {1, 2}; // 用小数组测试，日志更简洁
    vector<vector<int>> res = permute(nums);

    // 打印最终结果
    cout << "\n最终所有全排列：" << endl;
    for (auto &perm : res)
    {
        cout << "[";
        for (int num : perm)
            cout << num << ",";
        cout << "\b]" << endl;
    }
    return 0;
}