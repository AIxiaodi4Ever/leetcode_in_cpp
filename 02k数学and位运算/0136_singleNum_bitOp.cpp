class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (const int &num : nums) {
            result ^= num;
        }
        return result;
    }
};