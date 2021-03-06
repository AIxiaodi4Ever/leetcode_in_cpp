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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotonic-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 正常思路需要两次遍历，一次检查递增，一次检查递减
// 官方给出的方法二：使用比较流，小于时返回-1，大于时返回1,等于时返回0；
// 这样比较流中的数只有全是{-1, 0}或{0, 1}，单调才成立
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

    // 遍历结束说明单调
    return true;
}