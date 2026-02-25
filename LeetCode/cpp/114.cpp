#include <iostream>
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
    void flatten(TreeNode *root)
    {
        // 递归终止条件：空节点无需处理
        if (root == nullptr)
        {
            return;
        }

        // 1. 递归展开左子树和右子树
        flatten(root->left);
        flatten(root->right);
        // 2. 保存原右子树（避免被覆盖）
        TreeNode *tempRight = root->right;
        // 3. 将展开后的左子树挂载到根节点的right
        root->right = root->left;
        // 4. 左子树置空（题目要求链表仅用right指针）
        root->left = nullptr;
        // 画张图很快就清晰了，就是把左子树嫁接到右子树，将原先的右子树再接到最后
        // 5. 找到当前右子树（原左子树）的末尾节点
        TreeNode *cur = root;
        while (cur->right != nullptr)
        {
            cur = cur->right;
        }

        // 6. 将原右子树挂载到左子树的末尾
        cur->right = tempRight;
    }
};

// 测试代码：先序遍历打印链表（验证结果）
void preorderPrint(TreeNode *root)
{
    while (root != nullptr)
    {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

// 示例：构建二叉树并测试
int main()
{
    // 构建测试树：
    //      1
    //     / \
    //    2   5
    //   / \   \
    //  3   4   6
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);
    // 预期输出：1 2 3 4 5 6
    preorderPrint(root);

    // 释放内存（可选，避免内存泄漏）
    TreeNode *cur = root;
    while (cur != nullptr)
    {
        TreeNode *next = cur->right;
        delete cur;
        cur = next;
    }

    return 0;
}