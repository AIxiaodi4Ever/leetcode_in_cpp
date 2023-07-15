// 58. Length of Last Word

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto iter = s.rbegin();
        while (*iter == ' ' && iter != s.rend()) {
            ++iter;
        }
        uint32_t ans = 0;
        while (*iter != ' ' && iter != s.rend()) {
            ++ans;
            ++iter;
        }
        return ans;
    }
};