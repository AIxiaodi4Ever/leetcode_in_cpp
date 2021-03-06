class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        bool placed = false;
        vector<vector<int>> ans;
        int left = newInterval[0], right = newInterval[1];
        for (const vector<int>& interval : intervals)
        {
            if (placed)
                ans.emplace_back(interval);
            else if (interval[1] < left)
                ans.push_back(interval);
            else if (interval[0] > right)
            {
                if (!placed)
                {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            }
            else
            {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        // 最后都没有找到交集
        if (!placed)
            ans.push_back({left, right});
        return ans;
    }
};