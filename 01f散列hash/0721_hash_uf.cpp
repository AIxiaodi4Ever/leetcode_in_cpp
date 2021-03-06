
class UnionFind {
public:

    UnionFind(int _n) : f(vector<int>(_n, -1)), setCount(_n) {}

    int find(int x) 
    {
        return f[x] < 0 ? x : f[x] = find(f[x]);
    }

    bool unite(int x, int y) 
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (f[y] < f[x])
            swap(x, y);
        f[x] += f[y];
        f[y] = x;
        --setCount;
        return true;
    }

public:
    vector<int> f;
    int setCount;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emainToIndex;
        map<string, string> emainToName;
        int emailNums = 0;

        // �������Ų���¼ÿ�������Ӧ������
        for (const auto &account : accounts)
        {
            int size = account.size();
            string name = account[0];
            for (int i = 1; i < size; ++i)
            {
                string email = account[i];
                if (!emainToIndex.count(email))
                {
                    emainToIndex[email] = emailNums++;
                    emainToName[email] = name;
                }
            }
        }

        // �������ཻ������ͬ�˺ŵ���������ϲ�
        UnionFind uf(emailNums);
        for (const auto &account : accounts)
        {
            const string& firstEmail = account[1];
            int firstIndex = emainToIndex[firstEmail];
            int size = account.size();
            for (int i = 2; i < size; ++i)
            {
                const string& nextEmail = account[i];
                int nextIndex = emainToIndex[nextEmail];
                uf.unite(firstIndex, nextIndex);
            }
        }

        // �������ཻ���ı�ŵ����������hash
        map<int, vector<string>> IndexToEmails;
        for (const auto&[email, _] : emainToIndex)
        {
            int index = uf.find(emainToIndex[email]);
            IndexToEmails[index].emplace_back(email);
        }

        vector<vector<string>> merged;
        for (auto&[_, emails] : IndexToEmails)
        {
            // ����Ҫ�����ֵ���
            sort(emails.begin(), emails.end());
            vector<string> account;
            string& name = emainToName[emails[0]];
            account.emplace_back(name);
            for (const auto& email : emails)
                account.emplace_back(email);
            merged.emplace_back(account);
        }
        
        return merged;
    }
};