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
private:
    // 累加和变量（用成员变量避免递归传参）
    int total = 0;

    // 反向中序遍历的递归函数
    void dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return; // 递归终止条件：空节点直接返回
        }

        // 1. 先遍历右子树（BST右子树值更大）
        dfs(node->right);

        // 2. 更新当前节点值和累加和
        total += node->val;
        node->val = total;

        // 3. 再遍历左子树
        dfs(node->left);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        total = 0; // 每次调用重置累加和
        dfs(root);
        return root;
    }
};

// 辅助函数：中序遍历打印树（用于验证结果）
void inorderPrint(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

// 测试示例
int main()
{
    // 构建测试树：
    //       4
    //      / \
    //     1   6
    //    / \ / \
    //   0  2 5  7
    //        \   \
    //         3   8
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3)));
    root->right = new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8)));

    Solution s;
    TreeNode *res = s.convertBST(root);

    // 打印转换后的中序遍历结果（应输出：36 36 35 33 30 26 21 15 8）
    cout << "转换后的累加树中序遍历：";
    inorderPrint(res);
    cout << endl;

    // 释放内存（简单示例，实际可写递归释放函数）
    // 此处省略内存释放代码，避免示例冗余
    return 0;
}