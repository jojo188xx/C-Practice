#include <iostream>
#include <vector>
#include <stack>
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

// 1. 递归中序遍历（不变）
void inorder(TreeNode *root, vector<int> &res)
{
    if (root == nullptr)
        return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

// 2. 极简版：数组→二叉树（修正idx类型为size_t）
TreeNode *buildTreeSimple(const vector<int> &arr, size_t idx = 0)
{ // 关键：idx改为size_t
    // 边界：下标越界 或 当前值为-1（空节点）
    if (idx >= arr.size() || arr[idx] == -1)
        return nullptr;
    // 构造当前节点
    TreeNode *root = new TreeNode(arr[idx]);
    // 递归构造左孩子（2*idx+1）、右孩子（2*idx+2）
    root->left = buildTreeSimple(arr, 2 * idx + 1);
    root->right = buildTreeSimple(arr, 2 * idx + 2);
    return root;
}

// 3. 打印结果（极简版）
void printRes(const vector<int> &res)
{
    cout << "mid:";
    for (int x : res)
        cout << x << " ";
    cout << endl;
}

// 4. 释放内存（极简版）
void freeTree(TreeNode *root)
{
    if (!root)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main()
{
    // 你要的核心：直接写数组，一行构造树！
    vector<int> arr = {1, 2, 3, -1, -1, 4, 5}; // 完全二叉树数组
    TreeNode *root = buildTreeSimple(arr);

    // 中序遍历+打印
    vector<int> res;
    inorder(root, res);
    printRes(res);

    freeTree(root);
    return 0;
}