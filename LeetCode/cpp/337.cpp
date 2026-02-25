#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义二叉树节点结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int rob(TreeNode *root)
    {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }

private:
    pair<int, int> dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0};
        }
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        // 抢当前节点：左右子树都不能抢
        int rob_cur = node->val + left.second + right.second;
        // 不抢当前节点：左子树选最优 + 右子树选最优（核心修正处）
        int not_rob_cur = max(left.first, left.second) + max(right.first, right.second);
        return {rob_cur, not_rob_cur};
    }
}; // 测试用例（可选）
int main()
{
    // 构建测试树：[3,2,3,null,3,null,1]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Solution sol;
    cout << "max money=" << sol.rob(root) << endl; // 预期输出：7

    // 释放内存（避免内存泄漏）
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}