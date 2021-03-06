// 程序员面试金典02.01
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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

// 解题思路：hash表
// 使用一个数组记录链表中某一个数是否出现过，如果出现过则删除该节点

// followe up部分要求不使用额外的缓冲区，即不适用hash表
// 可以通过将时间复杂度由O(N)-->O(N^2)实现，两层循环，
// 外层循环保留第一个不重复的节点，内层循环删除所有重复的点。。(violent)

struct ListNode* removeDuplicateNodes(struct ListNode* head)
{
    int hash[20001] = {};
    struct ListNode *pos = head;

    if (pos == NULL)
    {
        return NULL;
    }

    hash[pos->val] = 1;

    // 从待删除节点的前驱节点开始遍历，这样pos->next是当前节点，pos->next->next是下一节点
    // 因为如果直接从当前节点开始遍历，无法将其前驱节点的指针指向下一节点
    while (pos->next != NULL)
    {
        // 重复则删除该节点，并pos保持不变以判断该节点的下一节点是否重复(下一节点变成了当前节点)
        if (hash[pos->next->val] == 1)
        {
            struct ListNode *temp = pos->next;
            pos->next = temp->next;
            free(temp);
        }
        // 不重复的pos = pos->next以判断下一节点是否重复
        else
        {
            hash[pos->next->val] = 1;
            pos = pos->next;
        }
    }

    return head;
}