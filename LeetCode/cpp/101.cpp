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
bool check(TreeNode *left, TreeNode *right)
{
    if (!left && !right) //!!判断是空！！
        return true;
    if (!left || !right)
        return false;
    return left->val == right->val && check(left->left, right->right) && check(left->right, right->left);
}
bool symmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    else
    {
        return check(root->left, root->right);
    }
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
    // 测试用例1：对称树 {1,2,2,3,4,4,3}
    vector<int> arr1 = {1, 2, 2, 3, 4, 4, 3};
    TreeNode *root1 = buildTreeSimple(arr1);
    bool ans1 = symmetric(root1);
    cout << "symmtest=" << boolalpha << ans1 << endl; // 输出 true

    // 测试用例2：非对称树 {1,2,3,-1,-1,4,5}
    vector<int> arr2 = {1, 2, 3, -1, -1, 4, 5};
    TreeNode *root2 = buildTreeSimple(arr2);
    bool ans2 = symmetric(root2);
    cout << "anti-smmytest=" << boolalpha << ans2 << endl; // 输出 false

    // 释放内存
    freeTree(root1);
    freeTree(root2);
    return 0;
}