#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void bk(vector<int> &candidates, int target, int start, int cursum, vector<int> &path, vector<vector<int>> &res)
{
    if (cursum == target)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        // 这题是重复取数字，不用加bool
        int num = candidates[i];
        if (cursum + num > target)
        {
            break;
        }
        path.push_back(num);
        bk(candidates, target, i, cursum + num, path, res); // 这里的i是为了重复
        path.pop_back();
    }
}
vector<vector<int>> combsum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    bk(candidates, target, 0, 0, path, res);
    return res;
}
int main()
{
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = combsum(candidates, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j != res[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != res.size() - 1)
            cout << ",";
    }
}