#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        // 1. 建图
        unordered_map<string, vector<pair<string, double>>> graph;
        unordered_set<string> nodes;
        for (int i = 0; i < equations.size(); ++i)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double v = values[i];
            graph[a].emplace_back(b, v);
            graph[b].emplace_back(a, 1.0 / v);
            nodes.insert(a);
            nodes.insert(b);
        }

        vector<double> res;
        for (auto &q : queries)
        {
            string c = q[0];
            string d = q[1];
            // 变量不存在
            if (!nodes.count(c) || !nodes.count(d))
            {
                res.push_back(-1.0);
                continue;
            }
            // BFS 找 c -> d 的路径乘积
            queue<pair<string, double>> q_bfs;
            unordered_set<string> visited;
            q_bfs.emplace(c, 1.0);
            visited.insert(c);
            double ans = -1.0;
            while (!q_bfs.empty())
            {
                auto [cur, val] = q_bfs.front();
                q_bfs.pop();
                if (cur == d)
                {
                    ans = val;
                    break;
                }
                for (auto &[neigh, w] : graph[cur])
                {
                    if (!visited.count(neigh))
                    {
                        visited.insert(neigh);
                        q_bfs.emplace(neigh, val * w);
                    }
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};