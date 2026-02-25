#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 全局函数，静态函数，匿名函数
bool comparepeople(const vector<int> &a, const vector<int> &b)
{
    if (a[0] != b[0])
    {
        return a[0] > b[0];
    }
    else
    {
        return a[1] < b[1];
    }
}
vector<vector<int>> rebuildque(vector<vector<int>> &people)
{
    sort(people.begin(), people.end(), comparepeople);
    vector<vector<int>> res;
    for (auto &p : people)
    {
        // 数组里的人是按 “身高降序、k 升序” 排好的
        // 当我们遍历到某个人 p 时，res 里已经存在的所有人，身高都 ≥ p 的身高。
        res.insert(res.begin() + p[1], p);
    }
    return res;
}
// 打印函数
void printVector(vector<vector<int>> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << "[" << vec[i][0] << "," << vec[i][1] << "]";
        if (i != vec.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}
// 主函数
int main()
{
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> result = rebuildque(people);
    cout << "res:";
    printVector(result);

    return 0;
}