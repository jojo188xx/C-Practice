#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // 用于equal函数

using namespace std;
vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    int len_s = s.size(), len_p = p.size();
    if (len_s < len_p)
    {
        return res;
    }
    vector<int> p_cnt(26, 0);
    vector<int> wd_cnt(26, 0);
    for (int i = 0; i < len_p; i++)
    {
        p_cnt[p[i] - 'a']++;
        wd_cnt[s[i] - 'a']++;
    }
    if (p_cnt == wd_cnt)
    {
        res.push_back(0);
    }
    for (int i = len_p; i < len_s; i++)
    {
        // 「窗口长度固定，右边界是 i，左边界就是 i - len_p + 1」
        wd_cnt[s[i - len_p] - 'a']--;
        wd_cnt[s[i] - 'a']++;
        if (p_cnt == wd_cnt)
        {
            res.push_back(i - len_p + 1);
        }
    }
    return res;
}
// 辅助函数：打印结果数组
void printResult(vector<int> &res)
{
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i];
        if (i != res.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
// 主函数：测试用例
int main()
{
    // 测试用例1（题目示例）
    string s1 = "cbaebabacd";
    string p1 = "abc";
    cout << "测试用例1：" << endl;
    cout << "s = \"" << s1 << "\", p = \"" << p1 << "\"" << endl;
    vector<int> res1 = findAnagrams(s1, p1);
    cout << "异位词起始索引：";
    printResult(res1);

    // 测试用例2
    string s2 = "abab";
    string p2 = "ab";
    cout << "\n测试用例2：" << endl;
    cout << "s = \"" << s2 << "\", p = \"" << p2 << "\"" << endl;
    vector<int> res2 = findAnagrams(s2, p2);
    cout << "异位词起始索引：";
    printResult(res2);

    // 测试用例3（边界情况）
    string s3 = "a";
    string p3 = "a";
    cout << "\n测试用例3：" << endl;
    cout << "s = \"" << s3 << "\", p = \"" << p3 << "\"" << endl;
    vector<int> res3 = findAnagrams(s3, p3);
    cout << "异位词起始索引：";
    printResult(res3);

    return 0;
}