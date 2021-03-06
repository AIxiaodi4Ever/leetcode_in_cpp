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
    int minSwapsCouples(vector<int>& row) 
    {
        int n = row.size();
        int tot = n / 2;
        UnionFind uf(tot);

        for (int i = 0; i < n; i += 2)
        {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            uf.unite(l, r);
        }

        int ans = tot - uf.setCount;
        return ans;
    }
};