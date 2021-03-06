class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), [](const vector<int>& x, const vector<int>& y)
        {
            return x[0] > y[0] || (x[0] == y[0] && x[1] < y[1]);
        });
        // ʹ����insert���Բ���Ҫֵ��ʼ��
        vector<vector<int>> ans;
        for (const vector<int>& person : people)
            ans.insert(ans.begin() + person[1], person);
        return ans;
    }
};