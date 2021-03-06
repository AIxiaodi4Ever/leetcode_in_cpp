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

/*
    枚举
    关键边的性质：不考虑该边则不连通或权值增加
    伪关键边：在已知该边不是关键边的前提下，先考虑这条边，最后的权值仍然不变
    上面的前提是因为，关键边也具有该性质，所以判断时先判断关键边，使用kruskal算法得到计算出最低的权值value，
    然后不考虑某条边，看权值是否增加或不连通，如果是，则为关键边，继续判断下一条，否则判断是否是伪关键边。
*/
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {
        int m = edges.size();
        UnionFind tempuf(n);
        // 编号
        for (int i = 0; i < m; ++i)
            edges[i].push_back(i);   

        // 排序
        sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2)->bool{
            return e1[2] < e2[2];
        });

        // kruskal算法，计算最小的value
        int value = 0;
        for (int i = 0; i < m; ++i)
        {
            if (tempuf.unite(edges[i][0], edges[i][1]))
                value += edges[i][2];
        }
        
        vector<vector<int>> ans(2);
        for (int i = 0; i < m; ++i)
        {
            UnionFind uf(n);
            int v = 0;
            for (int j = 0 ; j < m; ++j)
            {
                if (i != j && uf.unite(edges[j][0], edges[j][1]))
                    v += edges[j][2];
            }
            // 先判断关键边，因为关键边也具有非关键边的性质
            // 找到关键边后，直接判断下一条边
            if (uf.setCount != 1 || v > value)
            {
                ans[0].push_back(edges[i][3]);
                continue;
            }

            uf = UnionFind(n);
            uf.unite(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for (int j = 0; j < m; ++j)
            {
                if (j != i && uf.unite(edges[j][0], edges[j][1]))
                    v += edges[j][2];
            }
            // 不用判断是否连通，只有去除非关键边才会使图不连通
            if (v == value)
                ans[1].push_back(edges[i][3]);
        }
        return ans;
    }
};