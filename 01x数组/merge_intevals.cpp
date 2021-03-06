/*��Ŀ������
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

/*�ҵķ���˼·�ܼ򵥣���������⣬һ�仰�������ǰ�����⵱��һ������ƥ����⣺
����һ������(box)����ʼ��ÿ��Ԫ��Ϊ0������¼ƥ�����
���ȱ������룬ÿ�����俪ʼ��ֵ����box�±��Ӧ��λ��+1��ÿ�����������ֵ����box�±��Ӧ�ĵط�-1
Ȼ�����box(��0���������ܵ�������ֵ��������ֵ�����ڿ�ʼ������ʱ���¼һ��)���ۼ�box[i]����0
��ֵ����¼��cnt���档�����ĳ��λ��i��ʱ��cntΪ0����box[i]��Ϊ0����˵�����Ǻϲ�֮��������е�һ
����ʼ��λ�ã���left��¼���λ�ã�Ȼ��֪��cnt�лָ���0��˵����������������r��¼��ǰλ�ã�Ȼ���
left��right�ӵ���������С�

���ߣ�hamiguaex163com
���ӣ�https://leetcode-cn.com/problems/merge-intervals/solution/na-kong-jian-huan-shi-jian-er-qie-wo-mei-pai-xu-_-/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/
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