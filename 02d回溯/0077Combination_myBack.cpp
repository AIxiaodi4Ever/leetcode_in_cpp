class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) 
    {
        find_combination(1, n, k);
        return ans;
    }

    void find_combination(int i, int n, int k)
    {
        if (temp.size() + (n - i + 1) < k)
            return;

        if (temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        
        for (int j = i; j <= n; ++j)
        {
            temp.push_back(j);
            find_combination(j + 1, n, k);
            temp.pop_back();
        }
    }
};