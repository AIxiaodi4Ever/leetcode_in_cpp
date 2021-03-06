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
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf(2 * 1e4 + 1);
        int n = stones.size();
        for (int i = 0; i < n; ++i)
            uf.unite(stones[i][0], stones[i][1] + 1e4);
    
        // ͳ����ͨ������Ŀ
        // �����Լ���ģ���֮ǰ�Ĳ��裬ֻ�е��õ�洢����size��size��Ϊ1ʱ����˵���õ����ĳһ��ͨ���ĸ��ڵ�
        int num = 0;
        for (int i = 0; i < 2 * 1e4 + 1; ++i)
        {
            if (uf.f[i] < -1)
                ++num;
        }
        return n - num;
    }
};