// �Լ��Ĵ��룬�ϲ��˹ٷ���parent��size����
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
    ö��
    �ؼ��ߵ����ʣ������Ǹñ�����ͨ��Ȩֵ����
    α�ؼ��ߣ�����֪�ñ߲��ǹؼ��ߵ�ǰ���£��ȿ��������ߣ�����Ȩֵ��Ȼ����
    �����ǰ������Ϊ���ؼ���Ҳ���и����ʣ������ж�ʱ���жϹؼ��ߣ�ʹ��kruskal�㷨�õ��������͵�Ȩֵvalue��
    Ȼ�󲻿���ĳ���ߣ���Ȩֵ�Ƿ����ӻ���ͨ������ǣ���Ϊ�ؼ��ߣ������ж���һ���������ж��Ƿ���α�ؼ��ߡ�
*/
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {
        int m = edges.size();
        UnionFind tempuf(n);
        // ���
        for (int i = 0; i < m; ++i)
            edges[i].push_back(i);   

        // ����
        sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2)->bool{
            return e1[2] < e2[2];
        });

        // kruskal�㷨��������С��value
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
            // ���жϹؼ��ߣ���Ϊ�ؼ���Ҳ���зǹؼ��ߵ�����
            // �ҵ��ؼ��ߺ�ֱ���ж���һ����
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
            // �����ж��Ƿ���ͨ��ֻ��ȥ���ǹؼ��߲Ż�ʹͼ����ͨ
            if (v == value)
                ans[1].push_back(edges[i][3]);
        }
        return ans;
    }
};