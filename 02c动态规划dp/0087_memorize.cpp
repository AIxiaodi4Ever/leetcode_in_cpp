class Solution {
public:
    // 记忆化搜索存储状态数组
    // -1表示false, 1表示true，0表示未计算
    int memo[30][30][31];
    string s1, s2;

    bool checkSameWords(int i, int j, int length) {
        unordered_map<int, int> freq;
        for (int k = i; k < i + length; ++k) {
            ++freq[s1[k]];
        }
        for (int k = j; k < j + length; ++k) {
            --freq[s2[k]];
        }
        if (any_of(freq.begin(), freq.end(), [](const auto& entry)->bool{
            return entry.second != 0;
        })) {
            return false;
        }
        return true;
    }

    bool dfs(int i, int j, int length) {
        if (memo[i][j][length]) {
            return memo[i][j][length] == 1;
        } 

        // 检查两个字符串是否相等
        if (s1.substr(i, length) == s2.substr(j, length)) {
            memo[i][j][length] = 1;
            return true;
        }

        if (!checkSameWords(i, j, length)) {
            memo[i][j][length] = -1;
            return false;
        }

        // partition
        for (int k = 1; k < length; ++k) {
            // 不交换
            if (dfs(i, j, k) && dfs(i + k, j + k, length - k)) {
                memo[i][j][length] = 1;
                return true;
            }
            // 交换
            if (dfs(i, j + length - k, k) && dfs(i + k, j, length - k)) {
                memo[i][j][length] = 1;
                return true;
            }
        }

        memo[i][j][length] = -1;
        return false;
    }

    bool isScramble(string s1, string s2) {
        memset(memo, 0, sizeof(memo));
        this->s1 = s1;
        this->s2 = s2;
        return dfs(0, 0, s1.length());
    }
};