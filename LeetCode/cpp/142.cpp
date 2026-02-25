#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *detectCylcle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    // 能用 while (slow != fast) 的前提：必须先让快慢指针 “错开位置”（要么先移动一次，要么初始化时错开）
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            ListNode *id1 = head; //
            ListNode *id2 = slow;
            while (id1 != id2)
            {
                id1 = id1->next;
                id2 = id2->next;
            }
            return id1;
        }
    }
    return nullptr;
}
int main()
{
    // 完全按照你的方式手动构建带环链表
    ListNode *n3 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n0 = new ListNode(0);
    ListNode *n4 = new ListNode(-4);
    n3->next = n2;
    n2->next = n0;
    n0->next = n4;
    n4->next = n2;
    ListNode *entry = detectCylcle(n3);
    // 验证结果
    if (entry == n2)
    {
        cout << "succeed" << entry->val << endl;
    }
    else
    {
        cout << "fail" << endl;
    }
    return 0;
}