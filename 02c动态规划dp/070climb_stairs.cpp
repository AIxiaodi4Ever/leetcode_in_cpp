// leetcode:070
/* description:
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * Example 2:
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * ��Դ�����ۣ�LeetCode��
 * ���ӣ�https://leetcode-cn.com/problems/climbing-stairs
 * ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·����̬�滮
// ��ways(n)Ϊ������Ϊnʱ�ķ���������
// ��Ϊֻ���ʵ�1��2��������ways(n) = ways(n-1) + ways(n-2);
// ��ways(1) = 1, ways(2) = 2������ʹ�ù�������ways���ɡ�
int climbStairs(int n)
{
    // ��Ŀ�Ѽ���n >0
    int ways[2];
    ways[0] = 1;
    ways[1] = 2;

    if (n == 1)
        return 1;

    for (int i = 3; i <= n; i++)
    {
        int temp;
        temp = ways[1];
        ways[1] = ways[0] + ways[1];
        ways[0] = temp;
    }

    return ways[1];
}