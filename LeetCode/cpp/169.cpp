#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int func(vector<int> &nums)
{
    unordered_map<int, int> hash; /////下标是任意数，必须是map
    int cnt = 0, major = 0;
    for (int num : nums)
    {
        hash[num]++; /////老是错， 先自加才行
        if (hash[num] > cnt)
        {
            major = num;
            cnt = hash[num];
        }
    }
    return major;
}
int main()
{
    vector<int> nums = {2, 2, 2, 3, 3, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5};
    int ans = func(nums);
    cout << ans << endl;
    return 0;
}