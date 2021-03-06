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

// ����ͼtarjan�㷨���ű�ģ��
class tarjanSCC {
private:
    vector<vector<int>> &edges;
    vector<vector<int>> &edgesID;
    vector<int> dfn;
    vector<int> low;
    // �洢���
    vector<int> ans;
    // �ڵ���
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
        // ���
        for (int i = 0; i < m; ++i)
            edges[i].push_back(i);
        // ����
        sort(edges.begin(), edges.end(), [](const auto& v1, const auto& v2)->bool{
            return v1[2] < v2[2];
        });

        // ����������ͨ���Ĳ��ཻ��
        UnionFind uf(n);
        // �ߵı��
        vector<int> label(m, 0);
        vector<vector<int>> ans(2);
        for (int i = 0; i < m; )
        {
            /**********************************************************************/
            /* ����ͨ������Ϊ1ʱ˵��ͼ�Ѿ�ȫ����ͨ��֮������б߶����ǹؼ��߻�α�ؼ���*/
            /* ����ʱ�ð�ʣ�µ����б߱��α�Ի��ߣ������޷����α�ؼ���              */
            /*********************************************************************/
            if (uf.setCount == 1)
            {            
                for (int j = i; j < m; ++j)
                    label[edges[j][3]] = -1; // ���������Ѿ������ң�Ӧ�ð���ԭ������ű��
                break;
            }
            /* �ҳ�����Ȩֵ��ͬ�ıߣ���Χ[i, j) */
            int j = i;
            int w = edges[i][2];
            while (j < m && edges[j][2] == w)
                ++j;

            /******************************************/
            /* ͳ����������ȨֵΪw�ı�֮ǰ����ͨ��������*/
            /* ͬʱ���Ի��߱��Ϊ-1                    */
            /******************************************/
            int gn = 0;   // ������������Ȩֵw��֮ǰ����ͨ������������G�Ľڵ���
            unordered_map<int, int> compToID; // ����ÿ����ͨ���ı�ţ�����vector��Ϊһ��ʼ��֪����С
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
                else    // �Ի��߱��-1
                    label[edges[k][3]] = -1; // ���������Ѿ������ң�Ӧ�ð���ԭ������ű��
            }

            /************************************************************/
            /*��������Ȩֵαw�ķ��Ի��ߣ�����ͼG��Ѱ���ű�(���ؼ���)����� */
            /*������ͨ����Щ�����������е���ͨ�Ӽ�����û����uf����������Щ��*/
            /*��uf��������Щ�߾ͽ������µ���ͨ�Ӽ�                        */
            /************************************************************/
            vector<vector<int>> gm(gn), gmID(gn);  // ����ͼG�ıߣ���ͼG�еı���ԭedges�еı��
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
                ans[0].push_back(id);   // ѹ��ؼ���
                // ����õ���id����ԭ������ţ�����ֱ�ӱ��
                label[id] = 1;          // ����ű�(�ؼ���)
            }
            /* ��uf�д�������ȨֵΪw�ıߣ������µ���ͨ�� */
            /* Ȼ������һȨֵ */
            for (int k = i; k < j; ++k)
                uf.unite(edges[k][0], edges[k][1]);
        
            i = j;
        }

        /* �õ�����α�ؼ��ߣ������ű߷��Ի��� */ 
        for (int i = 0; i < m; ++i)
        {   
            if (!label[i])  // δ��ǹ��ı߼�Ϊα�ؼ���
                ans[1].push_back(i);
        }

        return ans;
    }
};