// 字符串 回溯 动态规划
class Solution {
private:
    vector<vector<int>> isSubPalindrome;
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
            // 不能用true,false因为除了0以外都是true
            if (isPalindrome(s, i, j) == 1)
            {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    // 记忆化搜索，0表示尚未搜索，1表示是回文，-1表示不是回文
    int isPalindrome(const string& s, int i, int j)
    {
        if (isSubPalindrome[i][j])
            return isSubPalindrome[i][j];
        if (i >= j)
            return isSubPalindrome[i][j] = 1;
        else
            return isSubPalindrome[i][j] = (s[i] == s[j]) ? isPalindrome(s, i + 1, j - 1) : -1;
    }

    vector<vector<string>> partition(string s) 
    {
        // 这个int导致类的成员变量n被覆盖，，导致直接返回空的ret。。。查了半天
        // int n = s.size();
        n = s.size();
        isSubPalindrome.assign(n, vector<int>(n));
        dfs(s, 0);
        return ret;
    }
};