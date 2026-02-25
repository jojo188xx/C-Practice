#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 修正后的递归版合并函数
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    // 递归终止条件：其中一个链表为空，返回另一个
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    // 选择较小的节点作为当前节点，递归合并剩余部分
    // 不用写while
    if (l1->val <= l2->val) ////
    {
        l1->next = mergeTwoLists(l1->next, l2); // 合并l1的下一个节点和l2
        return l1;                              ///                              // 返回当前选中的l1节点
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next); // 合并l1和l2的下一个节点
        return l2;                              ////                       // 返回当前选中的l2节点
    }
}

// 构建链表（ACM输入：以-1结束，如 1 2 4 -1）
ListNode *buildList()
{
    ListNode dummy(0);
    ListNode *curr = &dummy;
    int val;
    while (cin >> val && val != -1)
    {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy.next;
}

// 打印链表
void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val;
        if (curr->next)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

// 释放内存（避免泄漏）
void freeList(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        ListNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main()
{
    cout << "输入第一个有序链表（以-1结束）：" << endl;
    ListNode *l1 = buildList();
    cout << "输入第二个有序链表（以-1结束）：" << endl;
    ListNode *l2 = buildList();

    ListNode *merged = mergeTwoLists(l1, l2);
    cout << "合并结果：" << endl;
    printList(merged);

    freeList(merged); // 释放合并后的链表（包含原l1/l2的所有节点）
    return 0;
}