class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }

        int ans = 0;
        for (int num : nums) {
            if (freq[num] == 1) {
                ans = num;
                break;
            }
        }

        return ans;
    }
};