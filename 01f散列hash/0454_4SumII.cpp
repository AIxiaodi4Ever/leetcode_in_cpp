class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        unordered_map<int, int> countAB;
        for (const int& u : A)
        {
            for (const int & v : B)
                ++countAB[u + v];
        }
        int ans = 0;
        for (const int & u : C)
        {
            for (const int & v : D)
            {
                if (countAB.count(-u - v))
                    ans += countAB[-u - v];
            }
        }
        return ans;
    }
};