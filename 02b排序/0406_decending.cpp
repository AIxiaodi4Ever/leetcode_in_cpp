class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), [](const vector<int>& x, const vector<int>& y)
        {
            return x[0] > y[0] || (x[0] == y[0] && x[1] < y[1]);
        });
        // 使用了insert所以不需要值初始化
        vector<vector<int>> ans;
        for (const vector<int>& person : people)
            ans.insert(ans.begin() + person[1], person);
        return ans;
    }
};