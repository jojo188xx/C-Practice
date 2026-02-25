#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
    {
        return {};
    }
    sort(intervals.begin(), intervals.end()); //
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> &curr = intervals[i];
        vector<int> &last = res.back(); /// 加&指向内存地址，否则就是拷贝
        if (curr[0] <= last[1])
        {
            last[1] = max(last[1], curr[1]);
        }
        else
        {
            res.push_back(curr); /// 这里是把当前的推入，因为初始化已经推入了last
        }
    }
    return res;
}
void printIntervals(const vector<vector<int>> &intervals)
{
    cout << "[";
    for (int i = 0; i < intervals.size(); ++i)
    {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i != intervals.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main()
{

    vector<vector<int>> test1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    printIntervals(merge(test1));

    vector<vector<int>> test2 = {{1, 4}, {4, 5}};
    printIntervals(merge(test2));

    vector<vector<int>> test3 = {{4, 7}, {1, 4}};
    printIntervals(merge(test3));

    vector<vector<int>> test4 = {};
    printIntervals(merge(test4));
    return 0;
}