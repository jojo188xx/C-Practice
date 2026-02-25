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
ListNode *removefunc(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *fast = dummy;
    ListNode *slow = dummy;
    for (int i = 0; i < n; i++) /// i<n你要想清楚fast位置，一定自己模拟一遍
    {
        fast = fast->next;
    }
    while (fast->next != nullptr) ////A+B==B+A
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next; // 想一下只有两个节点，slow，fast，很简单的情况
    ListNode *newhead = dummy->next;
    return newhead;
}
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
// 主函数测试
int main()
{
    // 构建链表 1→2→3→4→5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *res = removefunc(head, 2);
    printList(res); // 输出：1 2 3 5

    return 0;
}