#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;
vector<int> merge(vector<int> left, vector<int> right)
{
    int i = 0, j = 0;
    vector<int> res;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            res.push_back(left[i]);
            i += 1;
        }
        else
        {
            res.push_back(right[j]);
            j += 1;
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
vector<int> mergesort(vector<int> &nums)
{
    if (nums.size() <= 1)
        return nums;
    int mid = nums.size() / 2;
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(mid + nums.begin(), nums.end());
    left = mergesort(left);
    right = mergesort(right);
    return merge(left, right);
}

int main(void)
{
    nums = {8, -4, 2, -1, 0};
    vector<int> ans = mergesort(nums);
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}