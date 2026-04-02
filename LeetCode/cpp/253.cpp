#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int minMeetingRooms(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return 0;
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });
    priority_queue<int, vector<int>, greater<int>> heap;
    heap.push(intervals[0][1]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= heap.top())
        {
            heap.pop();
        }
        heap.push(intervals[i][1]);
    }
    return heap.size();
}
int main()
{
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << minMeetingRooms(intervals1) << endl; // 输出 2
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << minMeetingRooms(intervals2) << endl; // 输出 1
    return 0;
}