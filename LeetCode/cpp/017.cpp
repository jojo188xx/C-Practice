#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
/// 必须是char
unordered_map<char, string> phonemap = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}}; // 双引号才是string
vector<string> res;
// 初始状态：index=0，path=""（空字符串）
// ├─ 处理数字2（index=0），对应字母a/b/c
// │  ├─ 拼a → path="a"，递归处理下一个数字（index=1）
// │  │  └─ 处理数字3（index=1），对应字母d/e/f
// │  │     ├─ 拼d → path="ad"，index=2（等于digits长度2）→ 加入结果
// │  │     ├─ 拼e → path="ae"，index=2 → 加入结果
// │  │     └─ 拼f → path="af"，index=2 → 加入结果
// │  ├─ 拼b → path="b"，递归处理下一个数字（index=1）
// │  │  └─ 处理数字3（index=1）
// │  │     ├─ 拼d → "bd" → 加入结果
// │  │     ├─ 拼e → "be" → 加入结果
// │  │     └─ 拼f → "bf" → 加入结果
// │  └─ 拼c → path="c"，递归处理下一个数字（index=1）
// │     └─ 处理数字3（index=1）
// │        ├─ 拼d → "cd" → 加入结果
// │        ├─ 拼e → "ce" → 加入结果
// │        └─ 拼f → "cf" → 加入结果
void backtrack(const string &digits, int index, string path)
{
    if (index == digits.size()) ////
    {
        res.push_back(path);
        return; ////
    }
    char digit = digits[index]; // char
    const string &letters = phonemap[digit];
    for (char letter : letters) //////
    {
        backtrack(digits, index + 1, path + letter); // path和letter顺序决定了输出
    }
}
vector<string> lettercomb(string digits)
{
    if (digits.empty())
    {
        return {};
    }
    backtrack(digits, 0, "");
    return res;
}
int main()
{
    string digits = "23";
    vector<string> result = lettercomb(digits);
    for (const string &s : result)
    {
        cout << s << " ";
    }
    return 0;
}