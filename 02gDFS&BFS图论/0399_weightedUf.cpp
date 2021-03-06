class Solution {
public:
    // 应用了路径压缩
    int findf(vector<int>& f, vector<double>& w, int x)
    {
        if (f[x] != x)
        {
            int father = findf(f, w, f[x]);
            w[x] = w[x] * w[f[x]];
            f[x] = father;
        }
        return f[x];
    }

    // 但没有灵巧合并
    void merge(int x, int y, double val, vector<int>&f, vector<double>& w)
    {
        int fx = findf(f, w, x);
        int fy = findf(f, w, y);
        if (fx == fy)
            return;
        f[fx] = fy;
        w[fx] = val * w[y] / w[x];
        
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 使用hash给每个字符编号
        unordered_map<string, int> variables;
        int nvars = 0;
        int n = equations.size();
        for (int i = 0; i < n; ++i)
        {
            if (variables.find(equations[i][0]) == variables.end())
                variables[equations[i][0]] = nvars++;
            if (variables.find(equations[i][1]) == variables.end())
                variables[equations[i][1]] = nvars++;
        }

        // 建立uf
        vector<int> f(nvars);
        vector<double> w(nvars, 1.0);
        for (int i = 0; i < nvars; ++i)
            f[i] = i;
        for (int i = 0; i < n; ++i)
        {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            merge(va, vb, values[i], f, w);
        }

        // 计算结果
        vector<double> ret;
        for (const auto& q : queries)
        {
            double result = -1.0;
            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end())
            {
                int ix = variables[q[0]], iy = variables[q[1]];
                int fx = findf(f, w, ix), fy = findf(f, w, iy);
                if (fx == fy)
                    result = w[ix] / w[iy];
            }
            ret.push_back(result);
        }
        return ret;
    }
};