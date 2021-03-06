// ����Ա���Խ��02.01
// description:
/*
Write code to remove duplicates from an unsorted linked list.

Example1:
 Input: [1, 2, 3, 3, 2, 1]
 Output: [1, 2, 3]

Example2:
 Input: [1, 1, 1, 1, 2]
 Output: [1, 2]

Note:
    The length of the list is within the range[0, 20000].
    The values of the list elements are within the range [0, 20000].

Follow Up:
How would you solve this problem if a temporary buffer is not allowed?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicate-node-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*struct ListNode {
    int val;
    struct ListNode *next;
};*/

// ����˼·��hash��
// ʹ��һ�������¼������ĳһ�����Ƿ���ֹ���������ֹ���ɾ���ýڵ�

// followe up����Ҫ��ʹ�ö���Ļ���������������hash��
// ����ͨ����ʱ�临�Ӷ���O(N)-->O(N^2)ʵ�֣�����ѭ����
// ���ѭ��������һ�����ظ��Ľڵ㣬�ڲ�ѭ��ɾ�������ظ��ĵ㡣��(violent)

struct ListNode* removeDuplicateNodes(struct ListNode* head)
{
    int hash[20001] = {};
    struct ListNode *pos = head;

    if (pos == NULL)
    {
        return NULL;
    }

    hash[pos->val] = 1;

    // �Ӵ�ɾ���ڵ��ǰ���ڵ㿪ʼ����������pos->next�ǵ�ǰ�ڵ㣬pos->next->next����һ�ڵ�
    // ��Ϊ���ֱ�Ӵӵ�ǰ�ڵ㿪ʼ�������޷�����ǰ���ڵ��ָ��ָ����һ�ڵ�
    while (pos->next != NULL)
    {
        // �ظ���ɾ���ýڵ㣬��pos���ֲ������жϸýڵ����һ�ڵ��Ƿ��ظ�(��һ�ڵ����˵�ǰ�ڵ�)
        if (hash[pos->next->val] == 1)
        {
            struct ListNode *temp = pos->next;
            pos->next = temp->next;
            free(temp);
        }
        // ���ظ���pos = pos->next���ж���һ�ڵ��Ƿ��ظ�
        else
        {
            hash[pos->next->val] = 1;
            pos = pos->next;
        }
    }

    return head;
}