/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // pre永远指向待反转区间的前一个
        ListNode* pre = dummy;
        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }

        ListNode* curr = pre->next;
        for (int i = left; i < right; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = pre->next;
            pre->next = nextNode;
        }

        return dummy->next;
    }
};