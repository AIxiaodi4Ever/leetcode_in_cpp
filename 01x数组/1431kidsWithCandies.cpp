/* leetcode:1431 */
// 题目描述
/* 
Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.
For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number 
of candies among them. Notice that multiple kids can have the greatest number of candies.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 解题思路
// 遍历找到拥有最多糖果的孩子的糖果数exist_greatest_candies
// 在此遍历，判断每一个孩子的糖果数加上extraCacdies是否大于exist_greatest_candies,是则为true，否则false
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
{
    int exist_greatest_candies = 0;
    bool *children =  (bool *)malloc(candiesSize * sizeof(bool));

    *returnSize = candiesSize;

    for (int i = 0; i < candiesSize; i++)
    {
        if (candies[i] > exist_greatest_candies)
            exist_greatest_candies = candies[i];
    }

    for (int i = 0; i < candiesSize; i++)
    {
        children[i] = candies[i] + extraCandies >= exist_greatest_candies ? true : false;
        /*if ((candies[i] + extraCandies >= exist_greatest_candies))
            children[i] = true;
        else
            children[i] = false;*/
    }

    return children;
}