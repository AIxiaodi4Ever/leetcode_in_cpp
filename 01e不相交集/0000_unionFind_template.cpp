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