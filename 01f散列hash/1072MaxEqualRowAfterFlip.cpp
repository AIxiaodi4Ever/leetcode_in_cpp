// leetcode:1072
/*description:
Given a matrix consisting of 0s and 1s, we may choose any number of columns in the matrix and 
flip every cell in that column.  Flipping a cell changes the value of that cell from 0 to 1 
or from 1 to 0.
Return the maximum number of rows that have all values equal after some number of flips.

Example 1:
Input: [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.

Example 2:
Input: [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.

Example 3:
Input: [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.

Note:
    1 <= matrix.length <= 300
    1 <= matrix[i].length <= 300
    All matrix[i].length's are equal
    matrix[i][j] is 0 or 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flip-columns-for-maximum-number-of-equal-rows
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路：
// 任意两行经过反转某些列后，每行上的数字都相等的条件是：
// 1.两行对应的数字全部相等，如 [0, 1, 0]和[0, 1, 0]；
// 2.两行异或之后所有的数字全是1, 如[1, 0, 1]和[0, 1, 0]；
// 又异或操作的交换律 a ^ b = c, 则 a ^ c = b；
// 所以解题过程如下：(正确题解使用hash，C的话不太方便)
// 使用数组EqualNums记录与第i行异或之后全1或全0的所有行数，遍历结束后返回EqualNums的最大值；
// 使用visited记录已经判断与之前行相同或互补的行，这样之后遍历时直接跳过
// 因为已经判断它与之前行相同或互补，说明所有与它相同或互补的行数已经记录在之前的EqualNums[i]中了，所以不会影响结果；

#define max(a, b) (((a) > (b)) ? (a):(b))

// 判断两行异或之后是否全1或全0
bool judge(int *row1, int *row2, int *matrixColSize)
{
    int temp = row1[0] ^ row2[0];
    
    for (int k = 1; k < *matrixColSize; k++)
    {
        if ((row1[k] ^ row2[k]) != temp)
            return false;
    }

    return true;
}

int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize)
{
    int EqualNums[matrixSize];
    int visited[matrixSize];
    int res = 1;

    if (matrix == NULL || matrixSize == 0 || *matrixColSize == 0)
        return 0;

    // 初始化
    for (int i = 0; i < matrixSize; i++)
    {
        EqualNums[i] = 1;
        visited[i] = 0;
    }

        // 外层
        for (int i = 0; i < matrixSize; i++)
        {
            // i已经判断过与之前的相同，则跳过
            if (visited[i] == 1)
                continue;

            for (int j = i + 1; j < matrixSize; j++)
            {
                // 同理，j已经判断过与之前的相同，则跳过
                if (visited[j] == 1)
                    continue;

                // matrixColSize是一个指针。。。。。不是整型
                if (judge(matrix[i], matrix[j], matrixColSize))
                {
                    EqualNums[i]++;
                    visited[j] = 1;
                }
            }
        }

        // 找出最大值
        for (int i = 0; i < matrixSize; i++)
        {
            // 上瘾了
            if (visited[i] == 1)
                continue;
            res = max(res, EqualNums[i]);
        }

    return res;
}