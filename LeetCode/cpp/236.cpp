#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // 默认构造可以不写
};
class Solution
{
public:
    TreeNode *lowestcommn(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == q || root == p)
        {
            return root;
        }
        TreeNode *left = lowestcommn(root->left, p, q);
        TreeNode *right = lowestcommn(root->right, p, q);
        if (left && right)
        {
            return root;
        }
        else if (left)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
};
// 构建二叉树：
//        3
//      /   \
//     5     1
//    / \   / \
//   6  2  0   8
//     / \
//    7   4
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    // 测试1：找5和1的最近公共祖先 → 3
    cout << sol.lowestcommn(root, root->left, root->right)->val << endl;
    // 测试2：找5和4的最近公共祖先 →5
    cout << sol.lowestcommn(root, root->left, root->left->right->right)->val << endl;

    return 0;
}