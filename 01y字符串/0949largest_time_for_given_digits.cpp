/* leetcode:949 */
/* descripiton:
Given an array of 4 digits, return the largest 24 hour time that can be made.
The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 
00:00, a time is larger if more time has elapsed since midnight.
Return the answer as a string of length 5.  If no valid time can be made, return 
an empty string.

 

Example 1:
Input: [1,2,3,4]
Output: "23:41"

Example 2:
Input: [5,5,5,5]
Output: ""

Note:
    A.length == 4
    0 <= A[i] <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-time-for-given-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

// 遍历所有的时间，当某一个时间合理且最大时，返回。。
char * largestTimeFromDigits(int* A, int ASize)
{
    char *largest_time = NULL;
    char *temp = (char *)malloc(sizeof(char) * 6);
    int max = -1, hours = 0, mins = 0;

    for (int i = 0; i < ASize; i++)
    {
        for (int j = 0; j < ASize; j++)
            if (j != i)
            {
                for (int k = 0; k < ASize; k++)
                {
                    if (k != j && k != i)
                    {
                        int l = 6 - i - j - k;
                        hours = 10 * A[i] + A[j];
                        mins = 10 * A[k] + A[l];
                        if (hours < 24 && mins < 60)
                        {
                            max = max > (hours * 100 + mins) ? max : (hours * 100 + mins);
                        }
                    }  
                }
            }
    }

    if (max < 0)
        return NULL;

    // 留个空存\0
    largest_time = (char *)malloc(sizeof(char) * 6);
    char temp1[6], temp2[6];
    sprintf(temp1, "%d", hours);
    temp1[2] = ':';
    temp1[3] = '\0';
    sprintf(temp2, "%d", mins);
    temp2[2] = '\0';
    largest_time = strcat(temp1, temp2);

    return largest_time;
}