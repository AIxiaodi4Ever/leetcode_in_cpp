/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 160 �㽶����
// ����˼·��˫ָ��+��ͷ�󽻻�
// ͦ��Ȥ�ģ�����ָ���������ָ��������ж�

/*
��������˫ָ�뷨
��������ָ�� pApApA �� pBpBpB���ֱ��ʼ��Ϊ���� A �� B ��ͷ��㡣Ȼ��������������������
    �� pApApA ���������β��ʱ�������ض�λ������ B ��ͷ��� (��û������������ B); ���Ƶģ��� pBpBpB ���������β��ʱ�������ض�λ������ A ��ͷ��㡣
    ����ĳһʱ�� pApApA �� pBpBpB �������� pApApA/pBpBpB Ϊ�ཻ��㡣
    ��Ū���Ϊʲô��������, ���Կ���������������: A={1,3,5,7,9,11} �� B={2,4,9,11}���ཻ�ڽ�� 9�� ���� B.length (=4) < A.length (=6)��pBpBpB �� pApApA �پ��� 222 ����㣬���ȵ���β������ pBpBpB �ض��� A ��ͷ��㣬pApApA �ض��� B ��ͷ����pBpBpB Ҫ�� pApApA ���� 2 ����㡣��ˣ����ǻ�ͬʱ���ｻ�㡣
    ���������������ཻ������ĩβ�Ľ���Ȼ��ͬ����˵� pApApA/pBpBpB ���������βʱ����¼������ A/B ��Ӧ��Ԫ�ء������Ԫ�ز���ͬ�������������ཻ��

���ߣ�LeetCode
���ӣ�https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *node1 = headA, *node2 = headB;
        // ���ཻ��ʱ������ָ���������������һ�飬������ָ��nullptr
        while (node1 != node2)
        {
            node1 = node1 != nullptr ? node1->next : headB;
            node2 = node2 != nullptr ? node2->next : headA;  
        }
        return node1;
    }
};