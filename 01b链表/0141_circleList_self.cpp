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
    bool hasCycle(ListNode *head) {
        if (!head) { return false; }
        ListNode* slowP = head, *fastP = head;
        while (slowP->next && fastP->next) {
            slowP = slowP->next;
            fastP = fastP->next->next;
            if (!fastP) {
                return false;
            } else if (slowP == fastP) {
                return true;
            }
        }
        return false;
    }
};