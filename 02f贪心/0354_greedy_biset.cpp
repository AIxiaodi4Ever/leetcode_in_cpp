// 贪心 二分 动态规划
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        if (envelopes.empty())
            return 0;

        sort(envelopes.begin(), envelopes.end(), [](auto &left, auto& right)->bool{
            return left[0] == right[0] ? left[1] > right[1] : left[0] < right[0];
        });

        int n = envelopes.size();
        vector<int> dp = {envelopes[0][1]};

        for (int i = 1; i < n; ++i)
        {
            int num = envelopes[i][1]; 
            if (num > dp.back())
            {
                dp.push_back(num);
            }
            else
            {
                auto it = lower_bound(dp.begin(), dp.end(), num);
                *it = num;
            }
        }
        return dp.size();
    }
};