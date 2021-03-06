class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) 
    {
        int n = A.size();
        vector<int> diff(n + 1);
        int ans = 0, revCnt = 0;
        for (int i = 0; i < n; ++i)
        {
            revCnt += diff[i];
            if ((A[i] + revCnt) % 2 == 0)
            {
                if (i + K > n)
                    return -1;
                ++ans;
                ++revCnt;
                --diff[i + K];
            }
        }
        return ans;
    }
};