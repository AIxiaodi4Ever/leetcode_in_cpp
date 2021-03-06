/* leetcode:739 */
/* description:
 * Given a list of daily temperatures T, return a list such that, for each day in the input, 
 * tells you how many days you would have to wait until a warmer temperature. If there is no 
 * future day for which this is possible, put 0 instead.
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output 
 * should be [1, 1, 4, 2, 1, 1, 0, 0].
 * Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an 
 * integer in the range [30, 100]. 
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 解法一：暴力，使用一个由于温度范围是[30, 100]，使用一个next数组保存每一个温度最早出现的位置;
// next中元素初始化为无穷大，反向遍历数组T，对于每个T[i]，在next中找到索引T[i]+1到100中，每个温度第一次出现的下标;
// 并将其中最小值标记为warmerIndex，则T[warmerIndex]为下一次比T[i]高的值，如果warmerIndex不等于无穷大，则ans[i] = warmerIndex - i;
// 最后令next[T[i]] = i;    时间复杂度O(nm), 空间复杂度O(m)，n是T的大小，m是next的大小。

// 这里使用解法二：
// 维持一个单调栈，正向遍历T，如果栈顶元素小于T[i]，则将栈顶元素T[prev_index]出栈，并将ans[prev_index]赋值为i - prev_index;
// 如果栈为空，或栈顶元素大于等于T[i]，则将T[i]入栈。
// ans初始全部赋值为0。
int* dailyTemperatures(int* T, int TSize, int* returnSize)
{
    // 为ans分配空间的同时初始化为0
    int *ans = (int *)calloc(TSize, sizeof(int));
    int temp_stack[TSize], top = -1;

    // 如果为空，返回空
    if (T == NULL)
        return NULL;

    // 否则正向遍历
    for (int i = 0; i < TSize; i++)
    {
        // 当栈不为空且栈顶元素小于T[i]时，出栈，并给ans对应的位置赋值
        while (top >= 0 && T[temp_stack[top]] < T[i])
        {
            ans[temp_stack[top]] = i - temp_stack[top];
            top--;

        }

        // 栈顶为空或栈顶元素大于T[i]时，入栈
        top++;
        temp_stack[top] = i;
    }

    *returnSize = TSize;
    return ans;
}