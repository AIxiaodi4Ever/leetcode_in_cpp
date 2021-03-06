// 并查集模板
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
 
/* 该树状数组并不通用，在其他题目里需要适当修改                               */
/* 数组的索引是每个点坐标的y-x值(y=x+b的截距b)                               */
/* 因为只处理P1区域，所以树状数组的索引为y-x即为y=x+b的截距b                  */
/* x大于正在处理的点，同时截距大于该点则一定在P1区域(上加下减)                */
/***************************************************************************/
/* 解法二的细节里面：对于P1区域.......其中最近点x1+y2最小。                   */
/* 其实就是在P1这个区域内，x1越小同时y1越小的点更加接近正在处理的点，          */
/* 无论正在处理的点在第几象限都是如此，而x1越小同时y1越小的结果就是x1+y1最小。 */
/***************************************************************************/
/* 按照横坐标从大到小处理，就可以保证x+y最小的值一定是P1区域距离当前点最近的点 */
/* 因为该点左边的点还没枚举到，右边的P1区域的点满足x+y最小就一定最近           */
/* 从大到小处理x同时索引用截距就保证了对每个点都能访问到p1区域的所有点         */
/* 树状数组 */
class BIT {
public:
    vector<int> tree, idRec;
    int n;

    BIT(int _n)
    {
        n = _n;
        tree.resize(n, INT_MAX);
        idRec.resize(n, -1);
    }

    int lowbit(int pos)
    {
        //return pos & (-pos);
        return pos & (~pos + 1);
    }

    /* pos递减的原因是保证所有截距(y-x)值小于pos的值都能找到pos代表的截距 */
    /* 最终保证能够找到正在处理的点的所有P1区域的点                      */
    void updata(int pos, int val, int id)
    {
        while (pos > 0)
        {
            // 更近即x+y更小时更新tree
            if (tree[pos] > val)
            {
                tree[pos] = val;
                idRec[pos] = id;
            }
            pos -= lowbit(pos);
        }
    }

    // 
    int query(int pos)
    {
        int minval = INT_MAX;
        int j = -1;
        while (pos < n)
        {
            // 更近即tree中保存的x+y更小时更新minval
            if (tree[pos] < minval)
            {
                minval = tree[pos];
                j = idRec[pos];
            }
            pos += lowbit(pos);
        }
        return j;
    }
};

struct Edge {
    int len, x, y;
    Edge(int _len, int _x, int _y) : len(_len), x(_x), y(_y) {}
    bool operator<(const Edge& e) const
    {
        return len < e.len;
    }
};

struct Pos {
    int x, y, id;
    bool operator<(const Pos& p) const
    {
        return x == p.x ? y < p.y : x < p.x;
    }
};

class Solution {
public:
    vector<Edge> edges;
    vector<Pos> positions;

    void build(int n)
    {
        // 根据横坐标排序
        sort(positions.begin(), positions.end());
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
        {
            a[i] = positions[i].y - positions[i].x;
            b[i] = positions[i].y - positions[i].x;
        }
        // 将截距排序，去除重复的截距
        sort(b.begin(), b.end());
        // unique将相邻的重复元素放在后面，并返回处理后第一个重复的迭代器
        // erase成员函数删除迭代器范围指定的元素
        b.erase(unique(b.begin(), b.end()), b.end());
        int num = b.size();
        // 树状数组从1开始
        BIT bit(num + 1);
        // 按横坐标从大到小处理每个点
        for (int i = n - 1; i >= 0; --i)
        {
            int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
            int j = bit.query(pos);
            if (j != -1)
            {
                int dis = abs(positions[i].x - positions[j].x) + abs(positions[i].y - positions[j].y);
                edges.emplace_back(dis, positions[i].id, positions[j].id);
            }
            bit.updata(pos, positions[i].x + positions[i].y, i);
        }
    }

    void solve(vector<vector<int>> &points, int n)
    {
        positions.resize(n);
        for (int i = 0; i < n; ++i)
        {
            positions[i].x = points[i][0];
            positions[i].y = points[i][1];
            positions[i].id = i;
        }
        /* 处理P1 */
        build(n); 
        /* 关于y=x对称过去，处理P2 */
        for (int i = 0; i < n; ++i)
        {
            swap(positions[i].x, positions[i].y);
        }
        build(n);    
        /* 再关于y = 0对称过去，处理P3 */
        for (int i = 0; i < n; ++i)
        {
            positions[i].x = -positions[i].x;
        }
        build(n);   // P3这个build(n)忘记写引发了一个错误，找了半天。操
        /* 再关于y=x对称过去，处理P4 */
        for (int i = 0; i < n; ++i)
        {
            swap(positions[i].x, positions[i].y);
        }
        build(n);
    }

    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        solve(points, n);
        sort(edges.begin(), edges.end());

        UnionFind uf(n);
        int ret = 0;
        for (const auto &e : edges)
        {
            if (uf.unite(e.x, e.y))
                ret += e.len;
            if (uf.setCount == 1)
                break;
        }
        return ret;
    }
};