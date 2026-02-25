#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> countMap;
    int maxcnt = 0;
    for (char task : tasks)
    {
        countMap[task]++;
        maxcnt = max(maxcnt, countMap[task]);
    }
    int maxcntnum = 0;
    for (auto &pair : countMap)
    {
        if (pair.second == maxcnt)
        {
            maxcntnum++;
        }
    }
    // 每一轮的「时间框架」（n 是冷却，+1 是任务本身的时间）。
    // 在第一步的框架最后，补上「所有最多任务的最后一次执行」
    int coretime = (maxcnt - 1) * (n + 1) + maxcntnum;
    //(2-1)*(2+1)+1 = 4，但任务总数是 6（A,A,B,C,D,E）。
    return max(coretime, (int)tasks.size());
}
// 测试示例
int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << leastInterval(tasks, n) << endl; // 输出：8

    // 额外测试用例：任务数多于冷却时间的情况
    vector<char> tasks2 = {'A', 'A', 'B', 'C', 'D', 'E'};
    int n2 = 2;
    cout << leastInterval(tasks2, n2) << endl; // 输出：6（任务总数）
    return 0;
}