#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return true;

    // 1. 快慢指针找中点
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. 反转后半段链表
    ListNode *prev = nullptr, *curr = slow->next;
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // 3. 双指针比较前后两段
    ListNode *left = head, *right = prev;
    while (right)
    {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }
    return true;

    // vector<int> nums;
    // while (head)
    // {
    //     nums.push_back(head->val);
    //     head = head->next;
    // }
    // int n = nums.size();
    // for (int i = 0, j = n - 1; i < n, j > 0; i++, j--)
    // {
    //     if (nums[i] != nums[j])
    //     {
    //         return false;
    //     }
    // }
    // return true;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    bool ans = isPalindrome(head);
    cout << ans << endl;
    return 0;
}