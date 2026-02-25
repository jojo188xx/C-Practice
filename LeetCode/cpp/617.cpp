#include <iostream>
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
class Solution
{
public:
    TreeNode *mergetree(TreeNode *root1, TreeNode *root2)
    {
        if (!root1)
            return root2;
        if (!root2)
            return root1;
        TreeNode *mergenode = new TreeNode(root1->val + root2->val);
        mergenode->left = mergetree(root1->left, root2->left);
        mergenode->right = mergetree(root1->right, root2->right);
        return mergenode;
    }
};
void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    // 简易层序遍历（用数组模拟队列，仅用于测试）
    TreeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        TreeNode *node = queue[front++];
        if (node != nullptr)
        {
            cout << node->val;
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
        else
        {
            cout << "null";
        }
        if (front < rear)
            cout << ",";
    }
    cout << "]" << endl;
}

int main()
{
    // 构建示例树1：[1,3,2,5]
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    // 构建示例树2：[2,1,3,null,4,null,7]
    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    Solution sol;
    TreeNode *mergedRoot = sol.mergetree(root1, root2);
    printTree(mergedRoot);

    // （可选）释放内存（OJ中无需手动释放，此处仅为规范）
    // 注：实际工程中需递归释放所有节点，避免内存泄漏
    return 0;
}