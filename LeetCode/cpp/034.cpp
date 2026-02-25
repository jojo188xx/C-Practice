#include <iostream>
#include <vector>
using namespace std;
int findfirst(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int res = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}
int findlast(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int res = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}
vector<int> searchrange(vector<int> &nums, int target)
{
    vector<int> res = {-1, -1};
    if (nums.empty())
        return res;
    int first = findfirst(nums, target);
    if (first == -1)
        return res;
    int last = findlast(nums, target);
    res[0] = first;
    res[1] = last;
    return res;
}