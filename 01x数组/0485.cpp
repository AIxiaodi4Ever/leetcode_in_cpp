class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxCons = 0, curCons = 0;
        for (int num : nums)
        {
            if (num == 1)
                ++curCons;
            else
            {
                maxCons = max(maxCons, curCons);
                curCons = 0;
            }
        }
        maxCons = max(maxCons, curCons);
        return maxCons;
    }
};