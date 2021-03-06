class UnionFind {
public:
    vector<int> parent;
    int n;
    // 当前并查集的数目
    int setCount;
public:
    UnionFind(int _n) : n(_n), setCount(_n), parent(vector<int>(_n, -1)) {}

    int find(int x)
    {
        return parent[x] < 0 ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (parent[y] < parent[x])
            swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        --setCount;
        return true;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int idx = i * n + j;
                if (i > 0) 
                    edges.emplace_back(idx - n, idx, abs(heights[i][j] - heights[i - 1][j]));
                if (j > 0)
                    edges.emplace_back(idx - 1, idx, abs(heights[i][j] - heights[i][j - 1]));
            }
        }
        sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2)->bool{
            return get<2>(e1) < get<2>(e2);
        });

        UnionFind uf(m * n);
        int ans = 0;
        for (const auto [x, y, v] : edges)
        {
            uf.unite(x, y);
            if (uf.connected(0, m * n - 1))
            {
                ans = v; 
                break;
            }
        }
        return ans;
    }
};