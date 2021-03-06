/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 160 香蕉链表
// 解题思路：双指针+到头后交换
// 挺有趣的，根据指针而不是其指向的内容判断

/*
方法三：双指针法
创建两个指针 pApApA 和 pBpBpB，分别初始化为链表 A 和 B 的头结点。然后让它们向后逐结点遍历。
    当 pApApA 到达链表的尾部时，将它重定位到链表 B 的头结点 (你没看错，就是链表 B); 类似的，当 pBpBpB 到达链表的尾部时，将它重定位到链表 A 的头结点。
    若在某一时刻 pApApA 和 pBpBpB 相遇，则 pApApA/pBpBpB 为相交结点。
    想弄清楚为什么这样可行, 可以考虑以下两个链表: A={1,3,5,7,9,11} 和 B={2,4,9,11}，相交于结点 9。 由于 B.length (=4) < A.length (=6)，pBpBpB 比 pApApA 少经过 222 个结点，会先到达尾部。将 pBpBpB 重定向到 A 的头结点，pApApA 重定向到 B 的头结点后，pBpBpB 要比 pApApA 多走 2 个结点。因此，它们会同时到达交点。
    如果两个链表存在相交，它们末尾的结点必然相同。因此当 pApApA/pBpBpB 到达链表结尾时，记录下链表 A/B 对应的元素。若最后元素不相同，则两个链表不相交。

作者：LeetCode
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *node1 = headA, *node2 = headB;
        // 无相交点时，两个指针各遍历两个链表一遍，并最终指向nullptr
        while (node1 != node2)
        {
            node1 = node1 != nullptr ? node1->next : headB;
            node2 = node2 != nullptr ? node2->next : headA;  
        }
        return node1;
    }
};