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

struct Edge {
    int len, x, y;
    Edge(int _len, int _x, int _y) : len(_len), x(_x), y(_y) {}
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // ¼ÆËã¾àÀëµÄlambda
        auto dist = [&](int i, int j)->int{
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };

        int n = points.size();
        vector<Edge> edges;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
                edges.emplace_back(dist(i, j), i, j);
        }

        sort(edges.begin(), edges.end(), [](const auto& e1, const auto &e2)->bool{
            return e1.len < e2.len;
        });

        // kruskal
        UnionFind uf(n);
        int cost = 0;
        for (const auto& e : edges)
        {
            if (uf.setCount == 1)
                break;
            if (uf.unite(e.x, e.y))
                cost += e.len;
        }
        return cost;
    }
};