// leetcode:896
/* decsription:
 * An array is monotonic if it is either monotone increasing or monotone decreasing.
An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone 
decreasing if for all i <= j, A[i] >= A[j].
Return true if and only if the given array A is monotonic.

Example 1:
Input: [1,2,2,3]
Output: true

Example 2:
Input: [6,5,4,4]
Output: true

Example 3:
Input: [1,3,2]
Output: false

Example 4:
Input: [1,2,4,5]
Output: true

Example 5:
Input: [1,1,1]
Output: true

Note:
    1 <= A.length <= 50000
    -100000 <= A[i] <= 100000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/monotonic-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·��Ҫ���α�����һ�μ�������һ�μ��ݼ�
// �ٷ������ķ�������ʹ�ñȽ�����С��ʱ����-1������ʱ����1,����ʱ����0��
// �����Ƚ����е���ֻ��ȫ��{-1, 0}��{0, 1}�������ų���
int compare_interger(int a1, int a2)
{
    if (a1 == a2)
        return 0;
    else
        return a1 > a2 ? 1 : -1;
}

bool isMonotonic(int* A, int ASize)
{
    int store = 0;
    int c;
    // 1 <= A.length <= 50000
    if (ASize == 1)
    {
        return true;
    }

    for (int i = 0; i < ASize - 1; i++)
    {
        c = compare_interger(A[i], A[i + 1]);
        if (c != 0)
        {
            if (c != store && store != 0)
                return false;
            store = c;
        }
    }

    // ��������˵������
    return true;
}