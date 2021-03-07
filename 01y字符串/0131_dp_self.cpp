// 字符串 回溯 动态规划
class Solution {
private:
    vector<vector<bool>> isSubPalindrome;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

public:
    void dfs(const string& s, int i)
    {
        if (i == n)
        {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; ++j)
        {
            if (isSubPalindrome[i][j])
            {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) 
    {
        // 这个int导致类的成员变量n被覆盖，，导致直接返回空的ret。。。查了半天
        // int n = s.size();
        n = s.size();
        isSubPalindrome.assign(n, vector<bool>(n, true));
        // 预处理类似manarch(马拉车)算法
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                isSubPalindrome[i][j] = (s[i] == s[j]) && isSubPalindrome[i + 1][j - 1];
            }
        }

        dfs(s, 0);
        return ret;
    }
};