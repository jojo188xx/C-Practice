#include <iostream>
#include <vector>
using namespace std;
int socket(vector<int> &price)
{
    if (price.empty())
    {
        return 0;
    }
    int maxprofit = 0;
    int minprice = price[0]; // 不是0
    for (int curprice : price)
    {
        minprice = min(curprice, minprice);
        maxprofit = max(maxprofit, curprice - minprice);
    }
    return maxprofit;
}
int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << socket(nums) << endl;
    return 0;
}
