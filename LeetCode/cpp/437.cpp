#include <iostream>
#include <unordered_map>
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
    int pathSum(TreeNode *root, int targetsum)
    {
        unordered_map<long long, int> prefixsum;
        prefixsum[0] = 1;
        return dfs(root, 0, targetsum, prefixsum);
    }

private:
    int dfs(TreeNode *node, long long currentsum, int targetsum, unordered_map<long long, int> &prefixsum)
    {
        if (node == nullptr)
            return 0;
        currentsum += node->val;
        int res = 0;
        if (prefixsum.find(currentsum - targetsum) != prefixsum.end())
        {
            res = prefixsum[currentsum - targetsum];
        }
        prefixsum[currentsum]++;
        res += dfs(node->left, currentsum, targetsum, prefixsum);
        res += dfs(node->right, currentsum, targetsum, prefixsum);
        prefixsum[currentsum]--;
        // 5. 回溯：移除当前前缀和（计数-1，若计数为0则删除键）
        if (prefixsum[currentsum] == 0)
        {
            prefixsum.erase(currentsum);
        }
        return res;
    }
}; // 主函数：构建示例树并测试
int main()
{
    // 构建示例二叉树：
    //         10
    //        /  \
    //       5   -3
    //      / \    \
    //     3   2   11
    //    / \   \
    //   3  -2   1
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 8;
    int result = sol.pathSum(root, targetSum);

    cout << "sum=" << targetSum << "roadcnt=" << result << endl; // 预期输出：3

    // 释放二叉树内存（避免内存泄漏）
    // 简易递归释放函数
    auto deleteTree = [](TreeNode *node, auto &&self) -> void
    {
        if (node == nullptr)
            return;
        self(node->left, self);
        self(node->right, self);
        delete node;
    };
    deleteTree(root, deleteTree);

    return 0;
}