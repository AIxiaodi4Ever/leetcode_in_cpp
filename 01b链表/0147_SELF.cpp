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
            // �ҵ������
            while (insertPos->next != nullptr && insertPos->val < head->val)
            {
                last = insertPos;
                insertPos = insertPos->next;
            }
            // ������������head��ֵ���ڵ�ǰ��
            if (insertPos->val < head->val && insertPos->next == nullptr)
            {
                ListNode* temp = new ListNode(head->val);
                insertPos->next = temp;
                head = head->next;
                continue;
            }
            // head��ֵС�ڵ�ǰ�㣬�ڵ�ǰ��ǰ�����
            ListNode* temp = new ListNode(head->val);
            temp->next = insertPos;
            // �ж��Ƿ����ͷ�ڵ�
            if (insertPos == orderedHead)
                orderedHead = temp;
            else
                last->next = temp;
            head = head->next;
        }
        return orderedHead;
    }
};