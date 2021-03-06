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
    ListNode* insertionSortList(ListNode* head) 
    {
        if (head == nullptr)
            return head;
        ListNode* orderedHead = new ListNode(head->val);
        head = head->next;
        while (head != nullptr)
        {
            ListNode* insertPos = orderedHead;
            ListNode* last = insertPos;
            // 找到插入点
            while (insertPos->next != nullptr && insertPos->val < head->val)
            {
                last = insertPos;
                insertPos = insertPos->next;
            }
            // 插入点在最后，且head的值大于当前点
            if (insertPos->val < head->val && insertPos->next == nullptr)
            {
                ListNode* temp = new ListNode(head->val);
                insertPos->next = temp;
                head = head->next;
                continue;
            }
            // head的值小于当前点，在当前点前面插入
            ListNode* temp = new ListNode(head->val);
            temp->next = insertPos;
            // 判断是否更新头节点
            if (insertPos == orderedHead)
                orderedHead = temp;
            else
                last->next = temp;
            head = head->next;
        }
        return orderedHead;
    }
};