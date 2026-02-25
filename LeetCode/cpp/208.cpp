#include <iostream>
#include <string>
using namespace std;

class Trie
{
private:
    // 定义字典树的节点结构体（私有化，封装性更好）
    struct TrieNode
    {
        bool isEnd;         // 标记是否是单词结尾
        TrieNode *next[26]; // 存放26个小写字母对应的子节点指针 a-z
        // 节点的构造函数：初始化每个节点
        TrieNode()
        {
            isEnd = false;
            // 初始化所有子节点指针为NULL，代表暂无子节点
            for (int i = 0; i < 26; i++)
            {
                next[i] = nullptr;
            }
        }
    };
    // 根节点指针，整个字典树的入口，私有成员变量
    TrieNode *root;

public:
    // 构造函数：初始化字典树，创建根节点
    Trie()
    {
        root = new TrieNode();
    }

    // 插入单词到字典树
    void insert(string word)
    {
        TrieNode *cur = root; // 从根节点开始遍历
        for (char ch : word)
        {                       // 遍历单词的每个字符
            int idx = ch - 'a'; // 字符转0-25的下标 a->0,z->25
            if (cur->next[idx] == nullptr)
            {                                    // 当前字符对应的子节点不存在
                cur->next[idx] = new TrieNode(); // 新建节点
            }
            cur = cur->next[idx]; // 指针移动到子节点
        }
        cur->isEnd = true; // 单词最后一个字符，标记为单词结尾
    }

    // 查询：是否存在【完整单词】word
    bool search(string word)
    {
        TrieNode *cur = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (cur->next[idx] == nullptr)
            { // 中途字符不存在，直接返回false
                return false;
            }
            cur = cur->next[idx];
        }
        // 必须走到最后，且当前节点是单词结尾，才算存在完整单词
        return cur->isEnd;
    }

    // 查询：是否存在【前缀】prefix
    bool startsWith(string prefix)
    {
        TrieNode *cur = root;
        for (char ch : prefix)
        {
            int idx = ch - 'a';
            if (cur->next[idx] == nullptr)
            { // 中途字符不存在，前缀不存在
                return false;
            }
            cur = cur->next[idx];
        }
        // 只要前缀遍历完，就说明存在该前缀，无需判断isEnd
        return true;
    }
};

// 测试用例（和你之前的测试逻辑一致）
int main()
{
    Trie trie;
    trie.insert("python");
    trie.insert("java");
    trie.insert("cpp");
    trie.insert("cplusplus");

    cout << trie.search("cpp") << endl;     // 1(true) 存在完整单词
    cout << trie.search("cp") << endl;      // 0(false) 只有前缀无完整单词
    cout << trie.startsWith("cp") << endl;  // 1(true) 存在前缀cp
    cout << trie.startsWith("jav") << endl; // 1(true) 存在前缀jav
    cout << trie.search("python3") << endl; // 0(false) 无此单词
    return 0;
}