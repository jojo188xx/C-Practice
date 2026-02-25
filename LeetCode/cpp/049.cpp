#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<vector<string>> groupsort(vector<string> &strs)
{
    unordered_map<string, vector<string>> groupsort; /// map的用法
    for (string &s : strs)
    {
        string key = s;
        sort(key.begin(), key.end());
        groupsort[key].push_back(s); // 同一个key要塞入多个s，所以map里设置要写vector
    }
    vector<vector<string>> res;
    for (auto &pair : groupsort)
    {
        res.push_back(pair.second); /////要明白map的构成key val
    }
    return res;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupsort(strs);
    for (auto &group : res)
    {
        for (auto &s : group)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}