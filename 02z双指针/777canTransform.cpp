// leetcode:777

/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", 
a move consists of either replacing one occurrence of "XL" with "LX", 
or replacing one occurrence of "RX" with "XR". Given the starting string 
start and the ending string end, return True if and only if there exists 
a sequence of moves to transform one string to the other.

Example:
Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Constraints:
    1 <= len(start) == len(end) <= 10000.
    Both start and end will only consist of characters in {'L', 'R', 'X'}.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-adjacent-in-lr-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路：同时满足转换不变性和可到达性
// L表示面向左边的人，R表示面向右边的人；
// 转换不变性：start和end字符串中的L和R的相对位置不变；
/************************************************************/
// 可到达性：第n个L不可能移动到初始位置之后，第n个R不可能移动到初始位置之前；
// 所以start中L的位置一定等于或在end中L的位置之前，同理start中的R一定在end中R之前或相等。
// 至于如何证明，，我不知道

bool canTransform(char * start, char * end)
{
    int len = strlen(start);
    int i = -1, j = -1;
    // 这里应该是 <= ， 题解有误
    // 如果用小于则第一个判断异或的if无法执行
    while (++i <= len && ++j <= len)
    {
        while(i < len && start[i] == 'X')
            ++i;
        while(j < len && end[j] == 'X')
            ++j;

        // 如果i和j中只有一个小于len，另一个等于n，
        // 则说明start和end中的一个包含的人数多于另一个；
        if ((i < len) ^ (j < len))
            return false;
        if (i < len && j < len)
        {
            if (start[i] != end[j] || (start[i] == 'L' && i < j) ||
                (start[i] == 'R' && i > j))
                return false;
        }
    }
    return true;
}