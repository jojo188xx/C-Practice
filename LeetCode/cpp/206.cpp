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
ListNode *reverlist(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *next_node = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next_node;
    }
    return pre;
}
int main()
{
    // 构造原链表：1->2->3->4->5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode *ans = reverlist(head);
    while (ans)
    {
        cout << ans->val << "->";
        ans = ans->next;
        /* code */
    }
    return 0;
}