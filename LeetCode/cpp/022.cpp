#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 一种是string cur，是字符串传递，复制字符串因此不需要push和pop
// 一种是vector容器，要用&和push和pop
void backtrack(vector<string> &result, string cur, int left, int right, int n)
{
    if (left == n && right == n)
    {
        result.push_back(cur);
        return;
    }
    if (left < n) // 从0开始计数的
    {
        backtrack(result, cur + '(', left + 1, right, n);
    }
    if (right < left)
    {
        backtrack(result, cur + ')', left, right + 1, n);
    }
}
vector<string> gp(int n)
{
    vector<string> result;
    backtrack(result, "", 0, 0, n);
    return result;
}
int main()
{

    vector<string> res = gp(3);
    for (const string &s : res)
    {
        cout << s << " ";
    }
}