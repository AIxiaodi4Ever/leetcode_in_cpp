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
Index of triangle in one grid
    \   /
    0\1/2
     /3\
    /   \ 
*/
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) 
    {
        int n = grid.size();
        // n * n * 4 rather than 4 * n
        UnionFind f(n * n * 4);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int idx = i * n + j;
                // 与下方方格合并、与右方方格合并
                if (i < n - 1)
                {
                    int bottom = idx + n;
                    f.unite(idx * 4 + 3, bottom * 4 + 1);  
                }
                if (j < n - 1)
                {
                    int right = idx + 1;
                    f.unite(idx * 4 + 2, right * 4);
                }

                // 根据方格内的字符合并三角形
                if (grid[i][j] == '/')
                {
                    f.unite(idx * 4, idx * 4 + 1);
                    f.unite(idx * 4 + 2, idx * 4 + 3);
                }
                else if (grid[i][j] == '\\')
                {
                    f.unite(idx * 4, idx * 4 + 3);
                    f.unite(idx * 4 + 1, idx * 4 + 2);
                }
                else
                {
                    f.unite(idx * 4, idx * 4 + 1);
                    f.unite(idx * 4 + 1, idx * 4 + 2);
                    f.unite(idx * 4 + 2, idx * 4 + 3);
                }
            }//j
        }//i
        return f.setCount;
    }
};