#include <iostream>
using namespace std;
// 注意null与nullptr的区别用法
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
bool hascycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next; ///
    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr) ///
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}