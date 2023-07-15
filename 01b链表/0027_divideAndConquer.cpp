// 23. Merge k Sorted Lists

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
        if (!a || !b) return a ? a : b;
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

    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        if (left > right) return nullptr;
        int mid = (left + right) >> 1;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);        
    }
};