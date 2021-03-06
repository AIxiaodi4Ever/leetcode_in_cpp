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
            // 大于等于给定x时根据是否是头节点分别处理
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
            // 小于时两个指针都往后移动一位
            else
            {
                prevNode = curNode;
                curNode = curNext;
            }

        }
        // 遍历到原本的originLast时单独处理
        if (curNode->val >= x && curLast != originLast)  // 忘记写=出错，
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