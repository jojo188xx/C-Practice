#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

// 定义二叉树节点结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // 构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // 析构函数（防止内存泄漏）
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

// 序列化与反序列化类
class Codec
{
public:
    // 序列化：把二叉树转成字符串（层序遍历）
    string serialize(TreeNode *root)
    {
        if (!root)
            return "null"; // 空树直接返回null

        queue<TreeNode *> q;
        q.push(root);
        string res;

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node)
            {
                // 非空节点，拼接值和分隔符
                res += to_string(node->val) + ",";
                // 不管子节点是否为空，都加入队列（保证结构完整）
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                // 空节点拼接null和分隔符
                res += "null,";
            }
        }

        // 移除最后一个多余的逗号
        if (!res.empty())
        {
            res.pop_back(); /// string res
        }
        return res;
    }

    // 反序列化：把字符串转回二叉树
    TreeNode *deserialize(string data)
    {
        if (data == "null")
            return nullptr; // 空字符串对应空树

        // 步骤1：分割字符串成节点值列表
        vector<string> vals;
        stringstream ss(data);
        string val;
        while (getline(ss, val, ','))
        {
            vals.push_back(val);
        }

        // 关键修复：idx改为size_t（无符号，和vals.size()类型一致）
        size_t idx = 0;
        TreeNode *root = new TreeNode(stoi(vals[idx++]));
        queue<TreeNode *> q;
        q.push(root);

        // 步骤3：按层序分配左右子节点
        while (!q.empty() && idx < vals.size())
        {
            TreeNode *parent = q.front();
            q.pop();

            // 处理左子节点
            if (vals[idx] != "null")
            {
                parent->left = new TreeNode(stoi(vals[idx]));
                q.push(parent->left);
            }
            idx++; // 无论是否为空，索引都要后移

            // 处理右子节点（需判断索引是否越界）
            if (idx < vals.size() && vals[idx] != "null")
            {
                parent->right = new TreeNode(stoi(vals[idx]));
                q.push(parent->right);
            }
            idx++;
        }

        return root;
    }
};

// 辅助函数：层序遍历打印二叉树（验证结果）
void printTree(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node)
        {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            cout << "null ";
        }
    }
    cout << endl;
}

// 主函数：测试逻辑
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // 步骤2：初始化序列化/反序列化对象
    Codec codec;

    // 步骤3：序列化
    string serializedStr = codec.serialize(root);
    cout << serializedStr << endl;

    // 步骤4：反序列化
    TreeNode *restoredRoot = codec.deserialize(serializedStr);
    printTree(restoredRoot);

    // 释放内存（防止内存泄漏）
    delete root;
    delete restoredRoot;

    return 0;
}