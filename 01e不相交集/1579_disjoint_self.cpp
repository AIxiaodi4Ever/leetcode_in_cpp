// 自己的代码，合并了官方的parent和size数组
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        UnionFind ufa(n), ufb(n);
        for (auto &e : edges)
        {
            --e[1];
            --e[2];
        }

        int ans = 0;
        // 公共边
        for (const auto &e : edges)
        {
            if (e[0] == 3)
            {
                if (!ufa.unite(e[1], e[2]))
                    ++ans;
                else
                    ufb.unite(e[1], e[2]);
            }
        }
        // 独占边
        for (const auto &e : edges)
        {
            if (e[0] == 1)
            {
                if (!ufa.unite(e[1], e[2]))
                    ++ans;
            }
            else if (e[0] == 2)
            {
                if (!ufb.unite(e[1], e[2]))
                    ++ans;
            }
        }
        return (ufa.setCount == 1 && ufb.setCount == 1) ? ans : -1;
    }
};