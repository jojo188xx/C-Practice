#include <vector>
#include <iostream>
using namespace std;
void dfs(vector<vector<char>> &grid, int i, int j)
{ // 作用就是淹没岛屿
    int rows = grid.size();
    int cols = grid[0].size();
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1')
    {
        return;
    }
    grid[i][j] = '0';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}
int numisland(vector<vector<char>> &grid)
{
    if (grid.empty() || grid[0].empty())
        return 0;
    int rows = grid.size();
    int cols = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1') ////
            {
                cnt++;
                dfs(grid, i, j);
            }
        }
    }
    return cnt;
}
int main()
{
    vector<vector<char>> grid1 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << numisland(grid1) << endl;
    return 0;
}