/* leetcode:1431 */
// ��Ŀ����
/* 
Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.
For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number 
of candies among them. Notice that multiple kids can have the greatest number of candies.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// ����˼·
// �����ҵ�ӵ������ǹ��ĺ��ӵ��ǹ���exist_greatest_candies
// �ڴ˱������ж�ÿһ�����ӵ��ǹ�������extraCacdies�Ƿ����exist_greatest_candies,����Ϊtrue������false
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