#include <iostream>
#include <unordered_map>
using namespace std;
struct DLinkedNode
{
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    // 无参构造和带参构造
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
class LRUCahe
{
private:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int capacity;
    int size;
    void addtohead(DLinkedNode *node) // 别和move搞混淆了
    {                                 // 双向链表,必须让每一个节点的前后都连接上
        // 顺序严格，从node改，一定保证能连上,优先子节点，然后后节点
        node->prev = head;       // node 的前驱指向虚拟头 head
        node->next = head->next; // node 的后继指向原来的第一个节点 firstNode
        // 此时只有 node 知道自己的前后节点，而原来head之后的节点不知道node的进入
        head->next->prev = node;
        head->next = node;
    } // 从后往前做链接
    void removeNode(DLinkedNode *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void movetohead(DLinkedNode *node)
    {
        removeNode(node); ///
        addtohead(node);
    }
    DLinkedNode *removetail()
    {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    // 声明顺序要一致
    LRUCahe(int _capacity) : capacity(_capacity), size(0)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode(); // 类成员变量飞局部变量
        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        DLinkedNode *node = cache[key];
        movetohead(node);
        return node->value;
    }
    void put(int key, int value)
    {
        if (cache.find(key) == cache.end())
        {
            DLinkedNode *node = new DLinkedNode(key, value); ////
            cache[key] = node;                               //
            addtohead(node);
            size++;
            if (size > capacity)
            {
                DLinkedNode *removed = removetail();
                cache.erase(removed->key); ////
                delete removed;
                size--;
            }
        }
        else // 找到这个数就要覆盖
        {
            DLinkedNode *node = cache[key];
            node->value = value; ///
            movetohead(node);
        }
    }
    ~LRUCahe()
    {
        DLinkedNode *cur = head;
        while (cur != nullptr)
        {
            DLinkedNode *next = cur->next;
            delete cur;
            cur = next;
        }
    }
};
int main()
{
    LRUCahe lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl; // 输出 1
    lru.put(3, 3);              // 淘汰 key=2
    cout << lru.get(2) << endl; // 输出 -1
    lru.put(4, 4);              // 淘汰 key=1
    cout << lru.get(1) << endl; // 输出 -1
    cout << lru.get(3) << endl; // 输出 3
    cout << lru.get(4) << endl; // 输出 4
    return 0;
}