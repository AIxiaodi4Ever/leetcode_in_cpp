class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // matrix is vector<vector<char>>
                if (matrix[i][j] == '1')
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
            }
        }
        int ret = 0;
        for (int j = 0; j < n; ++j)
        {
            // up存储从当前位置向上第一个left值小于当前位置的行索引
            // down存储从当前位置向下第一个left值小于当前位置的索引
            vector<int> up(m, 0), down(m, 0);
            stack<int> stk;
            for (int i = 0; i < m; ++i)
            {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j])
                    stk.pop();
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = stack<int>();
            for (int i = m - 1; i >= 0; --i)
            {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j])
                    stk.pop();
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }
            for (int i = 0; i < m; ++i)
            {
                int height = down[i] - up[i] - 1;
                ret = max(ret, height * left[i][j]);
            }
        }
        return ret;
    }
};