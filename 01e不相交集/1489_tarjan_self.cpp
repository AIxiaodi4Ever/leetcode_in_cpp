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

// 无向图tarjan算法求桥边模板
class tarjanSCC {
private:
    vector<vector<int>> &edges;
    vector<vector<int>> &edgesID;
    vector<int> dfn;
    vector<int> low;
    // 存储割边
    vector<int> ans;
    // 节点数
    int n;
    int ts;

private:
    void getCuttingEdge_(int u, int parentEdgeID)
    {
        dfn[u] = low[u] = ++ts;
        for (int i = 0; i < edges[u].size(); ++i)
        {
            int v = edges[u][i];
            int id = edgesID[u][i];
            if (dfn[v] == -1)
            {
                getCuttingEdge_(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    ans.push_back(id);
            }
            else if (id != parentEdgeID)
                low[u] = min(low[u], dfn[v]);
        }
    }

public:
    tarjanSCC(int _n, vector<vector<int>>& _edges, vector<vector<int>> &_edgesID) : edges(_edges), edgesID(_edgesID), 
        low(_n, -1), dfn(_n, -1), n(_n), ts(-1) {}

    vector<int> getCuttingEdge() 
    {
        for (int i = 0; i < n; ++i)
        {
            if (dfn[i] == -1)
                getCuttingEdge_(i, -1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {
        int m = edges.size();
        // 编号
        for (int i = 0; i < m; ++i)
            edges[i].push_back(i);
        // 排序
        sort(edges.begin(), edges.end(), [](const auto& v1, const auto& v2)->bool{
            return v1[2] < v2[2];
        });

        // 保存所有连通集的不相交集
        UnionFind uf(n);
        // 边的标记
        vector<int> label(m, 0);
        vector<vector<int>> ans(2);
        for (int i = 0; i < m; )
        {
            /**********************************************************************/
            /* 当连通集数量为1时说明图已经全部连通，之后的所有边都不是关键边或伪关键边*/
            /* 但此时得把剩下的所有边标记伪自环边，否则无法求得伪关键边              */
            /*********************************************************************/
            if (uf.setCount == 1)
            {            
                for (int j = i; j < m; ++j)
                    label[edges[j][3]] = -1; // 排序后序号已经被打乱，应该按照原本的序号标记
                break;
            }
            /* 找出所有权值相同的边，范围[i, j) */
            int j = i;
            int w = edges[i][2];
            while (j < m && edges[j][2] == w)
                ++j;

            /******************************************/
            /* 统计连接所有权值为w的边之前，连通集的数量*/
            /* 同时将自环边标记为-1                    */
            /******************************************/
            int gn = 0;   // 保存连接所有权值w的之前，连通集的数量，即G的节点数
            unordered_map<int, int> compToID; // 保存每个连通集的编号，不用vector因为一开始不知道大小
            for (int k = i; k < j; ++k)
            {
                int x = uf.find(edges[k][0]);
                int y = uf.find(edges[k][1]);
                if (x != y)
                {   
                    if (!compToID.count(x))
                        compToID[x] = gn++;
                    if (!compToID.count(y))
                        compToID[y] = gn++;
                }
                else    // 自环边标记-1
                    label[edges[k][3]] = -1; // 排序后序号已经被打乱，应该按照原本的序号标记
            }

            /************************************************************/
            /*连接所有权值伪w的非自环边，建立图G，寻找桥边(即关键边)并标记 */
            /*这里是通过这些边连接了所有的连通子集，并没有在uf真正连接这些边*/
            /*在uf中连接这些边就建立了新的连通子集                        */
            /************************************************************/
            vector<vector<int>> gm(gn), gmID(gn);  // 保存图G的边，即图G中的边在原edges中的编号
            for (int k = i; k < j; ++k)
            {
                int x = uf.find(edges[k][0]);
                int y = uf.find(edges[k][1]);
                if (x != y)
                {
                    int idx = compToID[x], idy = compToID[y];
                    gm[idx].push_back(idy);
                    gmID[idx].push_back(edges[k][3]);
                    gm[idy].push_back(idx);
                    gmID[idy].push_back(edges[k][3]);
                }
            }
            vector<int> bridges = tarjanSCC(gn, gm, gmID).getCuttingEdge();
            for (int &id : bridges)
            {
                ans[0].push_back(id);   // 压入关键边
                // 这里得到的id就是原本的序号，可以直接标记
                label[id] = 1;          // 标记桥边(关键边)
            }
            /* 在uf中处理所以权值为w的边，建立新的连通集 */
            /* 然后处理下一权值 */
            for (int k = i; k < j; ++k)
                uf.unite(edges[k][0], edges[k][1]);
        
            i = j;
        }

        /* 得到所有伪关键边，即非桥边非自环边 */ 
        for (int i = 0; i < m; ++i)
        {   
            if (!label[i])  // 未标记过的边即为伪关键边
                ans[1].push_back(i);
        }

        return ans;
    }
};