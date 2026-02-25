#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0;
        int col = cols - 1;
        while (row < rows && col >= 0)
        {
            int cur = matrix[row][col];
            if (cur == target)
            {
                return true;
            }
            else if (cur > target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    int target1 = 5;
    int target2 = 20;
    Solution sol;

    bool res1 = sol.searchMatrix(matrix, target1);
    bool res2 = sol.searchMatrix(matrix, target2);

    cout << "Search target " << target1 << " : " << boolalpha << res1 << endl;
    cout << "Search target " << target2 << " : " << boolalpha << res2 << endl;

    vector<vector<int>> emptyMatrix;
    vector<vector<int>> singleRow = {{1, 3, 5, 7}};
    vector<vector<int>> singleCol = {{1}, {2}, {3}};

    cout << "Empty matrix search result : " << sol.searchMatrix(emptyMatrix, 1) << endl;
    cout << "Single row search 3 : " << sol.searchMatrix(singleRow, 3) << endl;
    cout << "Single column search 5 : " << sol.searchMatrix(singleCol, 5) << endl;

    return 0;
}