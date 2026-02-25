#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq_map;
        for (int num : nums)
        {
            freq_map[num]++;
        }
        // less<T>（默认）：最大堆，优先把 “大的元素” 放到堆顶；
        // greater<T>：最小堆，优先把 “小的元素” 放到堆顶。
        // 存储类型，所用容器，排序方法，注意优先队列是排序第一个数，所以要换位置
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto &pair : freq_map)
        {
            int num = pair.first;
            int count = pair.second;
            min_heap.push({count, num});////要换位置
            if (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }
        vector<int> res;
        while (!min_heap.empty())
        {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        // 反转结果，得到频率从高到低的顺序（可选，题目不要求顺序则可省略）
        reverse(res.begin(), res.end());
        return res;
    }
};
// 测试用例
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution sol;
    vector<int> res = sol.topKFrequent(nums, k);

    // 输出结果：[1,2]

    for (int num : res)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}