class Solution {
public:


    int find(int idx, vector<int> &f)
    {
        if (f[idx] < 0)
            return idx;
        return f[idx] = find(f[idx], f);
    }

    void setUnion(vector<int> &f, int root1, int root2)
    {
        // 存储的是size的负值所以越小越大
        if (f[root1] < f[root2])
        {
            f[root1] += f[root2];
            f[root2] = root1; 
        }
        else
        {
            f[root2] += f[root1];
            f[root1] = root2;
        }
    }

    bool check(string &s1, string &s2, int m)
    {
        int num = 0;
        for (int i = 0; i < m; ++i)
        {
            if (s1[i] != s2[i])
                ++num;
            if (num > 2)
                return false;
        }
        return true;
    }   

    // 使用按大小合并的并查集
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> f(n, -1);

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int sz1 = find(i, f), sz2 = find(j, f);
                if (sz1 == sz2)
                    continue;
                if (check(strs[i], strs[j], m))
                    setUnion(f, sz1, sz2);
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            if (f[i] < 0)
                ++ret;
        }
        return ret;
    }
};