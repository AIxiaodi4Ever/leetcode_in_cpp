class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) 
    {
        int totalA = accumulate(A.begin(), A.end(), 0);
        int totalB = accumulate(B.begin(), B.end(), 0);
        int delta = (totalA - totalB) / 2;
        unordered_set alice(A.begin(), A.end());
        vector<int> ret(2, 0);
        for (const int &i : B)
        {
            int j = i + delta;
            if (alice.count(j))
            {
                ret = vector<int>{j, i};
                break;
            }
        }
        return ret;
    }
};