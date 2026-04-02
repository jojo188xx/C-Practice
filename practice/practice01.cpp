#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void heapsort(vector<int> &nums)
{
}

int main()
{
    vector<int> nums = {0, 2, -2, 0, 5, 3, -8};
    heapsort(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}