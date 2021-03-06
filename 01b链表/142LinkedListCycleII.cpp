/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        do
        {
            if (fast->next == nullptr || fast->next->next == nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        }while (slow != fast);

        ListNode *ptr = head;
        while (ptr != slow)
        {
            ptr = ptr->next;
            slow = slow->next;
        }
        return slow;
    }
};