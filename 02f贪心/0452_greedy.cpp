class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if (points.empty())
            return 0;

        sort(points.begin(), points.end(), [](const vector<int>&p1, const vector<int>&p2)->bool
        {
            return p1[1] < p2[1];
        });
        int pos = points[0][1];
        int ans = 1;
        for (const vector<int>& ballon : points)
        {
            if(ballon[0] > pos)
            {
                ++ans;
                pos = ballon[1];
            }
        }
        return ans;
    }
};