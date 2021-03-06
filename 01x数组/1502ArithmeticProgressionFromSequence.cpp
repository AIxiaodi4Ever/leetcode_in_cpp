// leetcode:1502
/*
Given an array of numbers arr. A sequence of numbers is called an arithmetic progression 
if the difference between any two consecutive elements is the same.
Return true if the array can be rearranged to form an arithmetic progression, otherwise, return false. 

Example 1:
Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

Example 2:
Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-make-arithmetic-progression-from-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
}
*/

// 排序之后检查每两个之间的差值是否相同即可

int my_cmp(void *p1, void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

bool canMakeArithmeticProgression(int* arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), my_cmp);
    int difference = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++)
    {
        int temp_diff = arr[i] - arr[i - 1];
        if (difference != temp_diff)
        {
            return false;
        }
        difference = temp_diff;
    }
    return true;
}