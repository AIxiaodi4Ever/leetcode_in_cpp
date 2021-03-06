// ���鼯ģ��
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // ��ǰ��ͨ������Ŀ
    int setCount;
    
public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }
    
    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }
    
    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

// Tarjan �㷨���ű�ģ��
class TarjanSCC {
private:
    const vector<vector<int>>& edges;
    const vector<vector<int>>& edgesId;
    vector<int> low;
    vector<int> dfn;
    vector<int> ans;
    int n;
    int ts;

private:
    void getCuttingEdge_(int u, int parentEdgeId) {
        low[u] = dfn[u] = ++ts;
        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            int id = edgesId[u][i];
            if (dfn[v] == -1) {
                getCuttingEdge_(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    ans.push_back(id);
                }
            }
            else if (id != parentEdgeId) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

public:
    TarjanSCC(int n_, const vector<vector<int>>& edges_, const vector<vector<int>>& edgesId_): \
        edges(edges_), edgesId(edgesId_), low(n_, -1), dfn(n_, -1), n(n_), ts(-1) {}
    
    vector<int> getCuttingEdge() {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                getCuttingEdge_(i, -1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto& u, const auto& v) {
            return u[2] < v[2];
        });

        UnionFind uf(n);
        vector<vector<int>> ans(2);
        vector<int> label(m);
        for (int i = 0; i < m;) {
            // �ҳ�����ȨֵΪ w �ıߣ��±귶ΧΪ [i, j)
            int w = edges[i][2];
            int j = i;
            while (j < m && edges[j][2] == edges[i][2]) {
                ++j;
            }

            // �洢ÿ����ͨ������ͼ G �еı��
            unordered_map<int, int> compToId;
            // ͼ G �Ľڵ���
            int gn = 0;
            
            for (int k = i; k < j; ++k) {
                int x = uf.findset(edges[k][0]);
                int y = uf.findset(edges[k][1]);
                if (x != y) {
                    if (!compToId.count(x)) {
                        compToId[x] = gn++;
                    }
                    if (!compToId.count(y)) {
                        compToId[y] = gn++;
                    }
                }
                else {
                    // ���Ի��߱��Ϊ -1
                    label[edges[k][3]] = -1;
                }
            }
            
            // ͼ G �ı�
            vector<vector<int>> gm(gn), gmid(gn);
            
            for (int k = i; k < j; ++k) {
                int x = uf.findset(edges[k][0]);
                int y = uf.findset(edges[k][1]);
                if (x != y) {
                    int idx = compToId[x], idy = compToId[y];
                    gm[idx].push_back(idy);
                    gmid[idx].push_back(edges[k][3]);
                    gm[idy].push_back(idx);
                    gmid[idy].push_back(edges[k][3]);
                }
            }

            vector<int> bridges = TarjanSCC(gn, gm, gmid).getCuttingEdge();
            // ���űߣ��ؼ��ߣ����Ϊ 1
            for (int id: bridges) {
                ans[0].push_back(id);
                label[id] = 1;
            }

            for (int k = i; k < j; ++k) {
                uf.unite(edges[k][0], edges[k][1]);
            }

            i = j;
        }

        // δ��ǵı߼�Ϊ���űߣ�α�ؼ��ߣ�
        for (int i = 0; i < m; ++i) {
            if (!label[i]) {
                ans[1].push_back(i);
            }
        }

        return ans;
    }
};