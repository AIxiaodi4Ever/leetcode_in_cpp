class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> RtoI;
        RtoI['I'] = 1;
        RtoI['V'] = 5;
        RtoI['X'] = 10;
        RtoI['L'] = 50;
        RtoI['C'] = 100;
        RtoI['D'] = 500;
        RtoI['M'] = 1000;

        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int value = RtoI[s[i]];
            if (i < n - 1 && value < RtoI[s[i + 1]]) {
                ans -= value;
            }
            else {
                ans += value;
            }
        }
        return ans;
    }
};