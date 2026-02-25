#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool bk(vector<vector<char>> &board, string &word, int i, int j, int k)
{
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k])
    {
        return false;
    }
    if (k == word.size() - 1) ///
    {
        return true;
    }
    // 记住如果回溯了就要复原
    char temp = board[i][j];
    board[i][j] = '\0';
    bool res = bk(board, word, i + 1, j, k + 1) ||
               bk(board, word, i - 1, j, k + 1) ||
               bk(board, word, i, j + 1, k + 1) ||
               bk(board, word, i, j - 1, k + 1);
    board[i][j] = temp; ///
    return res;
}
bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bk(board, word, i, j, 0)) // k=0
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << (exist(board, word) ? "yes" : "no") << endl; // 输出：存在

    // 测试用例2
    word = "SEE";
    cout << (exist(board, word) ? "yes" : "no") << endl; // 输出：存在

    // 测试用例3
    word = "ABCB";
    cout << (exist(board, word) ? "yes" : "no") << endl; // 输出：不存在

    return 0;
}