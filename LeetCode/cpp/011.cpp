#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxarea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int max_water = 0;
    while (left < right)
    {
        int cur_width = right - left;
        int cur_height = min(height[left], height[right]);
        int cur_water = cur_width * cur_height;
        if (cur_water > max_water)
        {
            max_water = cur_water;
        }
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return max_water;
}
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxarea(height) << endl; // 输出49
    return 0;
}