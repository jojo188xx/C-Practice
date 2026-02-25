#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(nullptr) {}
};
class Solution
{
public:
    ListNode *add_two_numb(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy; // 要记住怎么实现保存头结点***
        int carry = 0;
        while (l1 || l2 || carry) /// carry不要忘记
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            cur->next = new ListNode(digit);
            cur = cur->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return dummy->next;
    }
};
int main()
{ // 2-4-3
    ListNode *a1 = new ListNode(2);
    a1->next = new ListNode(4);
    a1->next->next = new ListNode(3);
    // 5-4-6
    ListNode *a2 = new ListNode(5);
    a2->next = new ListNode(6);
    a2->next->next = new ListNode(4);
    Solution sol;
    ListNode *res = sol.add_two_numb(a1, a2);
    while (res)
    {
        cout << res->val << " ";
        res = res->next; /* code */
    }
    cout << endl;
    return 0;
}