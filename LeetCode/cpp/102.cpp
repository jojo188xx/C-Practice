#include <vector>
#include <queue>
using namespace std;
#include <iostream>
// 二叉树节点定义（LeetCode通用）
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == nullptr) // null pointer of treenode 指向了空指针
        return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) /////////
    {
        int levelSize = q.size();
        vector<int> currentLevel;
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            // for循环内，下一层节点入队（先左后右，保证层内顺序）
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        res.push_back(currentLevel);
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = levelOrder(root);
    for (auto r : res)
    {
        for (int num : r)
        {
            cout << num << ",";
        }
    }
    // 输出结果：[[3], [9,20], [15,7]]
}