#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// 带权并查集：管理变量之间的连通关系和比值
class UnionFind
{
private:
    unordered_map<string, string> parent; // 记录每个变量的父节点
    unordered_map<string, double> weight; // 记录变量到父节点的比值（node / parent[node]）

public:
    // 初始化变量（如果未初始化过）
    void init(const string &x)
    {
        if (parent.find(x) == parent.end())
        {
            parent[x] = x;   // 初始父节点是自己
            weight[x] = 1.0; // 自己和自己的比值是1.0
        }
    }

    // 查找根节点，并进行路径压缩 + 权值更新
    string find(const string &x)
    {
        // 如果变量不存在，返回空字符串
        if (parent.find(x) == parent.end())
        {
            return "";
        }
        // 如果当前节点不是根节点，递归找根并更新路径
        if (parent[x] != x)
        {
            string orig_parent = parent[x]; // 保存原始父节点
            string root = find(parent[x]);  // 找到最终根节点
            // 路径压缩：直接挂到根节点上
            parent[x] = root;
            // 更新权值：x/root = x/orig_parent * orig_parent/root
            weight[x] *= weight[orig_parent];
        }
        return parent[x];
    }

    // 合并两个变量：x / y = val
    void unite(const string &x, const string &y, double val)
    {
        init(x);
        init(y);
        string root_x = find(x);
        string root_y = find(y);
        // 如果根不同，就把root_x合并到root_y上
        if (root_x != root_y)
        {
            parent[root_x] = root_y;
            // 推导root_x / root_y的比值：
            // x/y = val → x/root_x * root_x/root_y = val * y/root_y
            // → root_x/root_y = val * (y/root_y) / (x/root_x)
            weight[root_x] = val * weight[y] / weight[x];
        }
    }

    // 查询 x / y 的结果
    double query(const string &x, const string &y)
    {
        // 任意变量不存在，直接返回-1.0
        if (parent.find(x) == parent.end() || parent.find(y) == parent.end())
        {
            return -1.0;
        }
        string root_x = find(x);
        string root_y = find(y);
        // 不在同一个连通分量，返回-1.0
        if (root_x != root_y)
        {
            return -1.0;
        }
        // x/y = (x/root) / (y/root)
        return weight[x] / weight[y];
    }
};

// 核心解题函数
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    UnionFind uf;
    // 1. 构建带权并查集
    for (int i = 0; i < equations.size(); ++i)
    {
        string a = equations[i][0];
        string b = equations[i][1];
        double val = values[i];
        uf.unite(a, b, val);
    }
    // 2. 处理所有查询
    vector<double> res;
    for (auto &q : queries)
    {
        string c = q[0];
        string d = q[1];
        res.push_back(uf.query(c, d));
    }
    return res;
}

// 主函数：测试用例
int main()
{
    // 测试用例1
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    // 计算结果
    vector<double> result = calcEquation(equations, values, queries);

    // 输出结果
    cout << "res:" << endl;
    for (double val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // 测试用例2
    vector<vector<string>> equations2 = {{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}};
    vector<double> values2 = {3.0, 4.0, 5.0, 6.0};
    vector<vector<string>> queries2 = {{"x1", "x5"}, {"x5", "x2"}, {"x2", "x4"}, {"x2", "x2"}, {"x2", "x9"}, {"x9", "x9"}};
    vector<double> result2 = calcEquation(equations2, values2, queries2);

    cout << "res:" << endl;
    for (double val : result2)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}