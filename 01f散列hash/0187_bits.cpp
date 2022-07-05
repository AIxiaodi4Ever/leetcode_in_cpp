class Solution {
    unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    const int L = 10;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.size();
        if (n <= L) {
            return ans;
        }
        unordered_map<int, int> mp;
        // 这里x必须初始化为0，否则x的值是未定义的任意值
        int x = 0;
        for (int i = 0; i < L - 1; ++i) {
            x = (x << 2) | bin[s[i]];
        }
        // 循环遍历i的值表示窗口的左边界
        for (int i = 0; i <= n - L; ++i) {
            // 移位运算符的优先级低于算数运算符，得括起来
            x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << L * 2) - 1);
            if (++mp[x] == 2) {
                ans.push_back(s.substr(i, L));
            }
        }
        return ans;
    }
};