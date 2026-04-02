#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 链表节点定义
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // 小顶堆比较器
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> heap;

        // 把所有链表头入堆（注意判空）
        for (auto cc : lists)
        {
            if (cc) // 必须判断非空
                heap.push(cc);
        }

        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        while (!heap.empty())
        {
            ListNode *minnode = heap.top();
            heap.pop();

            cur->next = minnode;
            cur = cur->next;

            // 把下一个节点入堆
            if (minnode->next != nullptr)
            {
                heap.push(minnode->next);
            }
        }
        return dummy->next;
    }
};

// ===================== 工具函数 =====================

// 创建链表
ListNode *createList(vector<int> nums)
{
    if (nums.empty())
        return nullptr;
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    for (int num : nums)
    {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    return dummy->next;
}

// 打印链表
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// ===================== main 主函数 =====================
int main()
{
    // 构建 3 条有序链表
    vector<int> l1 = {1, 4, 5};
    vector<int> l2 = {1, 3, 4};
    vector<int> l3 = {2, 6};

    ListNode *list1 = createList(l1);
    ListNode *list2 = createList(l2);
    ListNode *list3 = createList(l3);

    // 放入数组
    vector<ListNode *> lists = {list1, list2, list3};

    Solution sol;
    ListNode *merged = sol.mergeKLists(lists);

    // 输出结果
    cout << "合并后的有序链表：";
    printList(merged);

    return 0;
}