class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), [](const vector<int>& x, const vector<int>&y)->bool{
            return (x[0] < y[0]) || (x[0] == y[0] && x[1] > y[1]);
        });
        // ��Ϊʹ����������������Ҫֵ��ʼ��
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const auto& person : people)
        {
            // Ӧ�����������������״�����Ż�
            int spaces = person[1] + 1;
            for (int i = 0; i < n; ++i)
            {
                if (ans[i].empty())
                    --spaces;
                if (!spaces)
                {
                    ans[i] = person;
                    break;
                }
            }
        }
        return ans;
    }
};