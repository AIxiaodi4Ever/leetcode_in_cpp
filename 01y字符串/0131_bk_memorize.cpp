// �ַ��� ���� ��̬�滮
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
            // ������true,false��Ϊ����0���ⶼ��true
            if (isPalindrome(s, i, j) == 1)
            {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    // ���仯������0��ʾ��δ������1��ʾ�ǻ��ģ�-1��ʾ���ǻ���
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
        // ���int������ĳ�Ա����n�����ǣ�������ֱ�ӷ��ؿյ�ret���������˰���
        // int n = s.size();
        n = s.size();
        isSubPalindrome.assign(n, vector<int>(n));
        dfs(s, 0);
        return ret;
    }
};