#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    ListNode *get_node(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr) ///
        {
            return nullptr;
        }
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != pb)
        {
            pa = pa == nullptr ? headB : pa->next; // 这里是写headb而不是pb
            pb = pb == nullptr ? headA : pb->next;
        }
        return pa;
    }
};
int main()
{
    ListNode *c1 = new ListNode(4);
    ListNode *c2 = new ListNode(5);
    ListNode *c3 = new ListNode(6);
    c1->next = c2;
    c2->next = c3;
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    a1->next = a2;
    a2->next = c1;
    ListNode *b1 = new ListNode(10);
    ListNode *b2 = new ListNode(20);
    ListNode *b3 = new ListNode(30);
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;
    Solution sol;
    ListNode *intersect = sol.get_node(a1, b1);
    if (intersect != nullptr)
    {
        cout << "intersect=" << intersect->val << endl;
    }
    else
    {
        cout << "no intersect" << endl;
    }
    delete a1;
    delete a2;
    delete b1;
    delete b2;
    delete b3;
    delete c1;
    delete c2;
    delete c3;
    return 0;
}