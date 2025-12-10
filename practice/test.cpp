#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> mergef(vector<int> left, vector<int> right)
{
    int i = 0, j = 0;
    vector<int> res;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            res.push_back(left[i]);
            i++;
        }
        else
        {
            res.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size())
    {
        res.push_back(left[i]);
        i++;
    }
    while (j < right.size())
    {
        res.push_back(right[j]);
        j++;
    }
    return res;
}
vector<int> funcsort(vector<int> &nums)
{
    if (nums.size() <= 1)
        return nums;
    int mid = nums.size() / 2;
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid, nums.end());
    left = funcsort(left);
    right = funcsort(right);
    return mergef(left, right);
}

int main(void)
{
    vector<int> nums = {8, -4, 2, -1, 0};
    vector<int> ans = funcsort(nums);
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}