/* 
题目描述
We are given hours, a list of the number of hours worked per day for a given employee.
A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
A well-performing interval is an interval of days for which the number of tiring days is strictly larger than 
the number of non-tiring days.
Return the length of the longest well-performing interval.

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-well-performing-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

// 解题思路：
// 前缀和+单调栈
// 数组hours里只有大于8和小于等于8两种情况，将大于8表示为1，小于等于8表示为-1，转化成数组arr；
// 原问题转化为求，数组的和大于0的子序列中长度最大者的长度
// 而使用数组保留前缀和presum以后，任意子序列和可以通过，前缀和的减法求出，例如：
// arr[1] + arr[2] +...+ arr[6] = presum[7] - presum[1];
// 原题解：https://leetcode-cn.com/problems/longest-well-performing-interval/solution/can-kao-liao-ji-ge-da-shen-de-ti-jie-zhi-hou-zong-/

#define max(a, b) (((a) >= (b)) ? (a) : (b))

int longestWPI(int* hours, int hoursSize)
{
    int presum[hoursSize + 1];
    int stk[hoursSize + 1], top;
    int best_int = 0;
    int i;

    // 将hours数组转化成1，-1数组,并求其前缀和
    presum[0] = 0;
    top = 0;
    stk[0] = 0;
    for (i = 0; i < hoursSize; i++)
    {
        if (hours[i] > 8)
            presum[i + 1] = presum[i] + 1;
        else
            presum[i + 1] = presum[i] - 1;
        
        // 将前缀和递减的元素索引入栈
        if (presum[i + 1] < presum[stk[top]])
        {
            stk[++top] = i + 1;
        }
    }

    for (int j = hoursSize; j >= 0; j--)
    {
        while (top >= 0)
        {
            // 执行这个判断，减少多余的运算
            if (j <= stk[top])
            {
                top--;
                break;
            }
            else if ((presum[j] - presum[stk[top]]) > 0)
            {
                best_int = max(best_int, j - stk[top]);
                top--;
            }
            else
                break;
        }
    }

    return best_int;
}