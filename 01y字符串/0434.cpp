class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                ++ans;
            }
        }
        return ans;
    }
};