class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, fast = 1;
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }

        return slow;
    }
};