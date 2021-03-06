/*题目描述：
Given a collection of intervals, merge all overlapping intervals.

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*我的方法思路很简单，很容易理解，一句话概括就是把这道题当成一个括号匹配的题：
定义一个数组(box)，初始化每个元素为0用来记录匹配情况
首先遍历输入，每个区间开始的值，在box下标对应的位置+1，每个区间结束的值，在box下标对应的地方-1
然后遍历box(从0到区间所能到达的最大值，这个最大值可以在开始遍历的时候记录一下)，累加box[i]不是0
的值，记录在cnt里面。如果到某个位置i的时候cnt为0，而box[i]不为0，这说明这是合并之后的区间中的一
个开始的位置，用left记录这个位置，然后知道cnt有恢复到0，说明这个区间结束，用r记录当前位置，然后把
left，right加到结果数组中。

作者：hamiguaex163com
链接：https://leetcode-cn.com/problems/merge-intervals/solution/na-kong-jian-huan-shi-jian-er-qie-wo-mei-pai-xu-_-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int box[10005];
    int keng[10005];
    int maxNum = 0;
    int left = 0, right = 0, cnt = 0;
    returnSize[0] = 0;
    int **returnArr = (int**)calloc(intervalsSize, sizeof(int*));
    returnColumnSizes[0] = (int*)calloc(intervalsSize, sizeof(int));
    for(int i = 0; i < intervalsSize; ++i) {
        returnArr[i] = (int*)calloc(2, sizeof(int));
        returnColumnSizes[0][i] = 2;
    }
    memset(box, 0, sizeof(box));
    memset(keng, 0, sizeof(keng));
    for(int i = 0; i < intervalsSize; ++i) {
        if(box[intervals[i][0]] == box[intervals[i][1]]) {
            keng[intervals[i][0]] = 1;
        }
        ++box[intervals[i][0]];
        --box[intervals[i][1]];
        maxNum = maxNum < intervals[i][1] ? intervals[i][1] : maxNum;
    }
    for(int i = 0; i <= maxNum; ++i) {
        if(!box[i] && keng[i] && cnt == 0) {
            returnArr[returnSize[0]][0] = i;
            returnArr[returnSize[0]++][1] = i;
        }
        if(box[i]) {
            if(cnt == 0) {
                left = i;
            }
            cnt += box[i];
            if(cnt == 0) {
                right = i;
                returnArr[returnSize[0]][0] = left;
                returnArr[returnSize[0]++][1] = right;
            }
        }
    }
    return returnArr;
}