#include <iostream>
#include <climits>
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
bool helper(TreeNode *node, long long lower, long long upper)
{
    if (node == nullptr)
        return true;
    if (node->val <= lower || node->val >= upper)
        return false;
    // 右子树所有节点必须 > 当前节点值（下限设为 node->val）

    bool isleftvalid = helper(node->left, lower, node->val);
    bool isrightvalid = helper(node->right, node->val, upper);
    return isleftvalid && isrightvalid;
}
bool isValidBST(TreeNode *root)
{
    // 初始调用：根节点的合法区间是 (long long)INT_MIN-1 到 (long long)INT_MAX+1
    // 用 long long 避免节点值为 INT_MAX/INT_MIN 时的溢出问题
    return helper(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << isValidBST(root); // 输出 true
    return 0;
}