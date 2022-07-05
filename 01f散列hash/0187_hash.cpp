class Solution {
    const int L = 10;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> mp;
        int n = s.length();
        for (int i = 0; i <= n - L; ++i) {
            string tmp = s.substr(i, L);
            if (++mp[tmp] == 2) {
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};