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
        unordered_set<ListNode*> seen;
        ListNode* current = head;
        while (current) {
            if (seen.count(current)) {
                return true;
            } else {
                seen.insert(current);
            }
            current = current->next;
        }
        return false;
    }
};