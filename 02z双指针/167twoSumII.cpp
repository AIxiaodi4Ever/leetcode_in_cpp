// leetcode:167
/*
    Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2.
Note:
    Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and 
you may not use the same element twice.

Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            int result = numbers[left] + numbers[right];
            if (result == target)
                return {left + 1, right + 1};
            else if (result < target)
                ++left;
            else
                --right;
        }
        return {-1, -1};
    }
};