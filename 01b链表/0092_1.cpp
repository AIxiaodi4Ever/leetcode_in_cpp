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
    void reverseList(ListNode* head) {
        ListNode* prev = nullptr, *curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

    /* 
    本题的思路是：
        1.先找到对应区间的前驱pre和后继节点succ
        2.断开这pre的next和只想succ的指针，让需要反转的区间孤立
        3.反转区间left,right
        4.另pre->next=right, left->next=succ, renturn head
    */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = dummy;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }

        ListNode* rightNode = pre;
        for (int i = left - 1; i < right; ++i) {
            rightNode = rightNode->next;
        }

        ListNode* leftNode = pre->next;
        ListNode* succ = rightNode->next;
        pre->next = nullptr;
        rightNode->next = nullptr;

        reverseList(leftNode);

        pre->next = rightNode;
        leftNode->next = succ;

        return dummy->next;
    }
};