// LeetCode:86
/* 题目描述 */
/* 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。 */
/* c语言实现 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
};
*/

struct ListNode* partition(struct ListNode* head, int x)
{
    if (head == 0)
    {
        return head;
    }

    struct ListNode header;
    struct ListNode *smallers, *tmp;

    header.next = head;
    tmp = &header;

    // 找到第一个最小元素并用smallers指针指向
    while (tmp->next)
    {
        if (tmp->next->val < x)
        {
            smallers = tmp->next;
            break;
        }
        tmp = tmp->next;
    }

    // 如果没有小于x的元素则直接返回head
    if(!tmp->next)   
    {
        return head;
    }
    // 找到小于x的元素，则使指针绕过该元素
    else
    {
        tmp->next = tmp->next->next;
    }

    // 将剩余小于x的元素加入smallers链表
    head = smallers;
    if (tmp->next)
    {
        tmp = &header;
        while (tmp->next)
        {
            if (tmp->next->val < x)
            {
                head->next = tmp->next;
                tmp->next = tmp->next->next;
                head = head->next;
            }
            else
            {
                tmp = tmp->next;
            }   
        }
    }

    // 合并两链表并返回
    head->next = header.next;
    return smallers;
}