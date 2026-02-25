#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool canFinish(int numcourses, vector<vector<int>> &prerequist)
{
    vector<vector<int>> adj(numcourses);
    vector<int> indegree(numcourses, 0);
    for (auto &p : prerequist)
    { // 先完成b-》a
        int a = p[0];
        int b = p[1];
        // 起点.push（终点）[b:a,c,d]
        adj[b].push_back(a);
        indegree[a]++;
    }
    queue<int> que;
    for (int i = 0; i < numcourses; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }
    int count = 0;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        count++;
        for (int next : adj[cur])
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                // 学完当前，加入下一批课程
                que.push(next);
            }
        }
    }
    return count == numcourses;
}
int main()
{
    int num = 2;
    vector<vector<int>> pre = {{1, 0}};
    cout << (canFinish(num, pre)) << endl;
    return 0;
}