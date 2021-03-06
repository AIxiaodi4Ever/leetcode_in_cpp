class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        vector<int> num(100, 0);
        int ret = 0;
        for (const auto &dom : dominoes)
        {
            int val = dom[0] < dom[1] ? dom[0] * 10 + dom[1] : dom[1] * 10 + dom[0];
            // ÿһ����ͬ��val���ͼ�����������ͬ��val���һ��
            ret += num[val];
            ++num[val];
        }
        return ret;
    }
};