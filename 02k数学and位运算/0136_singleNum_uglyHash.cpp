class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, bool> seen;
        for (const int & num : nums) {
            if (seen.count(num)) {
                seen[num] = false;
            } else {
                seen.insert({num, true});
            }
        }
        for (const auto& pair : seen) {
            if (pair.second) {
                return pair.first;
            }
        }
        return 0;
    }
};