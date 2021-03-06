/*题目描述:
    Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n 
vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

例：
Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/

/* 解题思路：看了题解，比较简单，双指针从两头遍历，只有中间的值高于其两边的位置时，接的水量才有可能增加 */
/* 因此每次计算体积时，将指向较小高度的指针向中间移动一位，再次计算体积，如果大于之前记录的max值，则更新 */

int maxArea(int* height, int heightSize)
{
    int vomlumn = 0;
    int maxVolumn = 0;
    int left = 0, right = heightSize - 1;

    while (left < right)
    {
        // 左边小
        if (height[left] < height[right])
        {
            vomlumn = height[left] * (right - left);
            left++;
        }
        // 右边小
        else if(height[left] > height[right])
        {
            vomlumn = height[right] * (right - left);
            right--;
        }
        // 相等
        else
        {
            vomlumn = height[left] * (right - left);
            left++;
            right--;
        }

        if (maxVolumn < vomlumn)
        {
            maxVolumn = vomlumn;
        }
    }

    return maxVolumn;
}