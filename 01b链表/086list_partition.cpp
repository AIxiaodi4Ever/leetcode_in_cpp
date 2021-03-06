// LeetCode:86
/* ��Ŀ���� */
/* ����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��
��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á� */
/* c����ʵ�� */

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

    // �ҵ���һ����СԪ�ز���smallersָ��ָ��
    while (tmp->next)
    {
        if (tmp->next->val < x)
        {
            smallers = tmp->next;
            break;
        }
        tmp = tmp->next;
    }

    // ���û��С��x��Ԫ����ֱ�ӷ���head
    if(!tmp->next)   
    {
        return head;
    }
    // �ҵ�С��x��Ԫ�أ���ʹָ���ƹ���Ԫ��
    else
    {
        tmp->next = tmp->next->next;
    }

    // ��ʣ��С��x��Ԫ�ؼ���smallers����
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

    // �ϲ�����������
    head->next = header.next;
    return smallers;
}