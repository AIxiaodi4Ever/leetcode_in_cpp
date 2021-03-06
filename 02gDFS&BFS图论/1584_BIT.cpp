// ���鼯ģ��
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
 
/* ����״���鲢��ͨ�ã���������Ŀ����Ҫ�ʵ��޸�                               */
/* �����������ÿ���������y-xֵ(y=x+b�Ľؾ�b)                               */
/* ��Ϊֻ����P1����������״���������Ϊy-x��Ϊy=x+b�Ľؾ�b                  */
/* x�������ڴ���ĵ㣬ͬʱ�ؾ���ڸõ���һ����P1����(�ϼ��¼�)                */
/***************************************************************************/
/* �ⷨ����ϸ�����棺����P1����.......���������x1+y2��С��                   */
/* ��ʵ������P1��������ڣ�x1ԽСͬʱy1ԽС�ĵ���ӽӽ����ڴ���ĵ㣬          */
/* �������ڴ���ĵ��ڵڼ����޶�����ˣ���x1ԽСͬʱy1ԽС�Ľ������x1+y1��С�� */
/***************************************************************************/
/* ���պ�����Ӵ�С�����Ϳ��Ա�֤x+y��С��ֵһ����P1������뵱ǰ������ĵ� */
/* ��Ϊ�õ���ߵĵ㻹ûö�ٵ����ұߵ�P1����ĵ�����x+y��С��һ�����           */
/* �Ӵ�С����xͬʱ�����ýؾ�ͱ�֤�˶�ÿ���㶼�ܷ��ʵ�p1��������е�         */
/* ��״���� */
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

    /* pos�ݼ���ԭ���Ǳ�֤���нؾ�(y-x)ֵС��pos��ֵ�����ҵ�pos����Ľؾ� */
    /* ���ձ�֤�ܹ��ҵ����ڴ���ĵ������P1����ĵ�                      */
    void updata(int pos, int val, int id)
    {
        while (pos > 0)
        {
            // ������x+y��Сʱ����tree
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
            // ������tree�б����x+y��Сʱ����minval
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
        // ���ݺ���������
        sort(positions.begin(), positions.end());
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
        {
            a[i] = positions[i].y - positions[i].x;
            b[i] = positions[i].y - positions[i].x;
        }
        // ���ؾ�����ȥ���ظ��Ľؾ�
        sort(b.begin(), b.end());
        // unique�����ڵ��ظ�Ԫ�ط��ں��棬�����ش�����һ���ظ��ĵ�����
        // erase��Ա����ɾ����������Χָ����Ԫ��
        b.erase(unique(b.begin(), b.end()), b.end());
        int num = b.size();
        // ��״�����1��ʼ
        BIT bit(num + 1);
        // ��������Ӵ�С����ÿ����
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
        /* ����P1 */
        build(n); 
        /* ����y=x�Գƹ�ȥ������P2 */
        for (int i = 0; i < n; ++i)
        {
            swap(positions[i].x, positions[i].y);
        }
        build(n);    
        /* �ٹ���y = 0�Գƹ�ȥ������P3 */
        for (int i = 0; i < n; ++i)
        {
            positions[i].x = -positions[i].x;
        }
        build(n);   // P3���build(n)����д������һ���������˰��졣��
        /* �ٹ���y=x�Գƹ�ȥ������P4 */
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