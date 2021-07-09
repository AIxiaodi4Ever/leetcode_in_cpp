class Solution {
private:
    int rob(vector<int>& nums) {
        int size = nums.size();
        // 因为输入的数最小为1，所以无需考虑size < 2
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            int temp = first;
            first = second;
            second = max(temp + nums[i], second);
        }
        return second;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for (int val : nums) {
            maxVal = max(maxVal, val);
        }

        vector<int> sum(maxVal + 1, 0);
        for (int val : nums) {
            sum[val] += val;
        }

        return rob(sum);
    }
};