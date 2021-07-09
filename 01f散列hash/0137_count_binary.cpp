class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int val : nums) {
                total += ((val >> i) & 1);
            }
            if (total % 3) {
                // |= is equal to +=
                ans |= (1 << i);
            }
        }
        return ans;
    }
};