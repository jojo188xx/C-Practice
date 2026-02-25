#include <iostream>
using namespace std;
class Solution
{
public:
    int hammindistance(int x, int y)
    {
        int xor_val = x ^ y; // xor是一个专有词，不要用
        int cnt = 0;
        while (xor_val)
        {
            xor_val &= xor_val - 1; // 多理解，4&5消除末位1,快速到0；
            // cnt += cur & 1;cur = cur >> 1;
            cnt++;
        }
        return cnt;
    }
};
int main()
{
    Solution sol;
    cout << sol.hammindistance(4, 5) << endl;
    cout << sol.hammindistance(1, 4) << endl;
}
