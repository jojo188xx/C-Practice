#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
#include <queue>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
unordered_map<int, int> inorderMap;
TreeNode *helper(vector<int> &preorder, int preL, int preR, int inL, int inR)
{
    if (preL > preR) ///
        return nullptr;
    int rootval = preorder[preL];
    TreeNode *root = new TreeNode(rootval);
    int rootidxin = inorderMap[rootval]; // 这个是inorder的下标，不适用preorder
    int leftsize = rootidxin - inL;
    // 这里的位置写法，要记住参考传入的参数，起点位置，终点位置，都是指向当前位置
    root->left = helper(preorder, preL + 1, preL + leftsize, inL, rootidxin - 1);
    root->right = helper(preorder, preL + leftsize + 1, preR, rootidxin + 1, inR);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        inorderMap[inorder[i]] = i;
    }
    return helper(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preorder, inorder);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();
        cout << cur->val << " ";

        if (cur->left != nullptr)
        {
            q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
        }
    }
    cout << endl;
}