#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int depth(TreeNode *node, int &maxd) // 要把maxd给传进去
{
    if (node == nullptr)
    {
        return 0;
    }
    int left_depth = depth(node->left, maxd);
    int right_depth = depth(node->right, maxd);
    maxd = max(maxd, left_depth + right_depth);
    return max(left_depth, right_depth) + 1; // 就差一点
}
int cntd(TreeNode *root)
{
    int maxd = 0;
    depth(root, maxd); // 可以丢失返回
    return maxd;
}
int main()
{
    // 构建示例树：
    //     1
    //    / \
    //   2   3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << "D=" << cntd(root) << endl; // 预期输出2

    // 释放内存（避免内存泄漏）
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}