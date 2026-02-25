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
bool huiwenlist(ListNode *head)
{
    vector<int> nums;
    while (head)
    {
        nums.push_back(head->val);
        head = head->next;
    }
    int n = nums.size();
    for (int i = 0, j = n - 1; i < n, j > 0; i++, j--)
    {
        if (nums[i] != nums[j])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    bool ans = huiwenlist(head);
    cout << ans << endl;
    return 0;
}