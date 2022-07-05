// 链表头节点不变，后续节点依次作为链表的尾部、头部，返回更新后的链表

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* formatList(ListNode* head) {
        // write code here
        ListNode* curHead = head;
        ListNode* curTail = head->next;
        ListNode* nextHead, *nextTail;
        while (curTail != nullptr && curTail->next != nullptr) {
            nextHead = curTail->next;
            if (nextHead != nullptr) {
                nextTail = nextHead->next;
                nextHead->next = curHead;
                curTail->next = nextTail;
                curHead = nextHead;
                curTail = nextTail;
            }
        }
        return curHead;
    }
};