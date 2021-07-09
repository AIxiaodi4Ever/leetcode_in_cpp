class Solution {
private:
    vector<string> wordsRev;
    unordered_map<string_view, int> indices;
public:
    int findWord(const string_view& s, int left, int right)
    {
        auto iter = indices.find(s.substr(left, right - left + 1));
        return iter == indices.end() ? -1 : iter->second;
    }

    bool isPalindrome(const string_view& s, int left, int right)
    {
        int half = (right - left + 1) / 2;
        for (int i = 0; i < half; ++i)
        {
            if (s[left + i] != s[right - i])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        int n = words.size();
        for (const string& word : words)
        {
            wordsRev.push_back(word);
            reverse(wordsRev.back().begin(), wordsRev.back().end());
        }
        // 将字符串的反转输入哈希表
        for (int i = 0; i < n; ++i)
        {
            indices.emplace(wordsRev[i], i);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < n; ++i)
        {
            int m = words[i].size();
            if (!m)
                continue;
            string_view wordView(words[i]);
            for (int j = 0; j <= m; ++j)
            {
                if (isPalindrome(wordView, j, m - 1))
                {
                    int right_id = findWord(wordView, 0, j - 1);
                    if (right_id != -1 && right_id != i)
                        ret.push_back({i, right_id});
                }
                // 同样,条件j为了避免重复s1前后缀为空且剩余部分不是回文时，字符串索引重复
                if (j && isPalindrome(wordView, 0, j - 1))
                {
                    int left_id = findWord(wordView, j, m - 1);
                    if (left_id != -1 && left_id != i)
                        ret.push_back({left_id, i});
                }
            }
        }
        return ret;
    }
};