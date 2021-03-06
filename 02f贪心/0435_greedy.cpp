class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.empty())
            return 0;
        
        sort(intervals.begin(), intervals.end(), [](const auto& e1, const auto& e2)->bool{
            return e1[1] < e2[1];
        });
        
        int n = intervals.size();
        int ans = 1, curRight = intervals[0][1];
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][0] >= curRight)
            {
                ++ans;
                curRight = intervals[i][1];
            }
        }   
        return n - ans;
    }
};