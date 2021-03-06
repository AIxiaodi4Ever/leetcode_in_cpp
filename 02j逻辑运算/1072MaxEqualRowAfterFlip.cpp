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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/flip-columns-for-maximum-number-of-equal-rows
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·��
// �������о�����תĳЩ�к�ÿ���ϵ����ֶ���ȵ������ǣ�
// 1.���ж�Ӧ������ȫ����ȣ��� [0, 1, 0]��[0, 1, 0]��
// 2.�������֮�����е�����ȫ��1, ��[1, 0, 1]��[0, 1, 0]��
// ���������Ľ����� a ^ b = c, �� a ^ c = b��
// ���Խ���������£�(��ȷ���ʹ��hash��C�Ļ���̫����)
// ʹ������EqualNums��¼���i�����֮��ȫ1��ȫ0���������������������󷵻�EqualNums�����ֵ��
// ʹ��visited��¼�Ѿ��ж���֮ǰ����ͬ�򻥲����У�����֮�����ʱֱ������
// ��Ϊ�Ѿ��ж�����֮ǰ����ͬ�򻥲���˵������������ͬ�򻥲��������Ѿ���¼��֮ǰ��EqualNums[i]���ˣ����Բ���Ӱ������

#define max(a, b) (((a) > (b)) ? (a):(b))

// �ж��������֮���Ƿ�ȫ1��ȫ0
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

    // ��ʼ��
    for (int i = 0; i < matrixSize; i++)
    {
        EqualNums[i] = 1;
        visited[i] = 0;
    }

        // ���
        for (int i = 0; i < matrixSize; i++)
        {
            // i�Ѿ��жϹ���֮ǰ����ͬ��������
            if (visited[i] == 1)
                continue;

            for (int j = i + 1; j < matrixSize; j++)
            {
                // ͬ��j�Ѿ��жϹ���֮ǰ����ͬ��������
                if (visited[j] == 1)
                    continue;

                // matrixColSize��һ��ָ�롣����������������
                if (judge(matrix[i], matrix[j], matrixColSize))
                {
                    EqualNums[i]++;
                    visited[j] = 1;
                }
            }
        }

        // �ҳ����ֵ
        for (int i = 0; i < matrixSize; i++)
        {
            // �����
            if (visited[i] == 1)
                continue;
            res = max(res, EqualNums[i]);
        }

    return res;
}