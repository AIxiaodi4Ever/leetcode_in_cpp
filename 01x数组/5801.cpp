class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> arrT(n, 0);
        for (int i = 0; i < n; ++i) {
            arrT[i] = ceil((float)dist[i] / speed[i]);
        }
        sort(arrT.begin(), arrT.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // arrT[i]为怪物到达的时间，i为开枪时间
            if (arrT[i] > i) ++ans;
            else {
                return ans;
            }
        }
        return ans;
        
    }
};