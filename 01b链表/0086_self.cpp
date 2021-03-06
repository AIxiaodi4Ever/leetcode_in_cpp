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
    ListNode* partition(ListNode* head, int x) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* originLast = head;
        while (originLast->next != nullptr)
            originLast = originLast->next;    
        ListNode* curLast = originLast;
    
        ListNode* curNode = head, *prevNode = new ListNode(), *beforeHead = new ListNode();
        prevNode->next = head, beforeHead->next = head;
        while (curNode != originLast)
        {
            ListNode* curNext = curNode->next;
            // ���ڵ��ڸ���xʱ�����Ƿ���ͷ�ڵ�ֱ���
            if (curNode->val >= x)
            {
                if (prevNode->next == beforeHead->next)
                    beforeHead->next = curNext;

                prevNode->next = curNext;
                curNode->next = nullptr;
                curLast->next = curNode;
                curLast = curNode;
                curNode = curNext;
            }
            // С��ʱ����ָ�붼�����ƶ�һλ
            else
            {
                prevNode = curNode;
                curNode = curNext;
            }

        }
        // ������ԭ����originLastʱ��������
        if (curNode->val >= x && curLast != originLast)  // ����д=����
        {
            if (prevNode->next == beforeHead->next)
                beforeHead->next = curNode->next;
            prevNode->next = curNode->next;
            curNode->next = nullptr;
            curLast->next = curNode;
        }

        return beforeHead->next;
    }
};