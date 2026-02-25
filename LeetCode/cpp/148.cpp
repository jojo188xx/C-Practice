#include <iostream>
using namespace std;

// 定义链表节点结构
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
    ListNode *sortList(ListNode *head)
    {
        // 递归终止条件：空链表 或 只有一个节点（已排序）
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // 步骤1：用快慢指针找到链表中点（拆分链表）
        ListNode *mid = findMiddle(head);
        ListNode *rightHead = mid->next;
        mid->next = nullptr; // 切断链表，分成左、右两部分

        // 步骤2：递归拆分左、右链表，直到最小单元
        // 创建新节点
        ListNode *left = sortList(head);
        ListNode *right = sortList(rightHead);

        // 步骤3：合并两个有序链表
        return mergeTwoLists(left, right);
    }

private:
    // 快慢指针找中点（快指针走两步，慢指针走一步，快指针到尾时慢指针在中点）
    ListNode *findMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next; // 快指针从第二个节点开始，避免偶数节点时死循环
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 合并两个有序链表（经典题）
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // 虚拟头节点，简化链表拼接逻辑
        // 用栈上对象（ListNode dummy(0)）的好处：
        // 无需手动释放内存，函数执行结束后，栈上的 dummy 会自动销毁，避免内存泄漏。
        ListNode dummy(0);
        ListNode *curr = &dummy; // 记住curr直接放在dummy上

        // 逐个比较两个链表的节点，小的先接入结果
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // 拼接剩余的节点（其中一个链表已遍历完）
        curr->next = (l1 != nullptr) ? l1 : l2;

        return dummy.next; // 虚拟头节点的下一个节点是真正的头
    }
};

// 辅助函数：打印链表
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// 测试用例
int main()
{
    // 构建测试链表：4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution s;
    ListNode *sortedHead = s.sortList(head);
    printList(sortedHead); // 输出：1 2 3 4

    // 释放内存（可选，避免内存泄漏）
    ListNode *temp;
    while (sortedHead != nullptr)
    {
        temp = sortedHead;
        sortedHead = sortedHead->next;
        delete temp;
    }

    return 0;
}