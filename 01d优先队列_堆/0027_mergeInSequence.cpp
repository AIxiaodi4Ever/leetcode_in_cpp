// Merge k Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode head, *nodeBeforeTail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val >= bPtr->val) {
                nodeBeforeTail->next = bPtr;
                bPtr = bPtr->next;
            } else {
                nodeBeforeTail->next = aPtr;
                aPtr = aPtr->next;
            }
            nodeBeforeTail = nodeBeforeTail->next;
        }
        nodeBeforeTail->next = aPtr ? aPtr : bPtr;
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for (int i = 0; i < lists.size(); ++i) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};