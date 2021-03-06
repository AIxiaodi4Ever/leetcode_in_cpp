class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) 
    {
        int n = A.size();
        vector<int> diff(n + 1);
        int ans = 0, revCnt = 0;
        for (int i = 0; i < n; ++i)
        {
            revCnt ^= diff[i];
            if (A[i] == revCnt)    // A[i] ^ revCnt == 0, 因为二者不是0就是1所以如果相等它们之和对2异或一定为0
            {
                if (i + K > n)
                    return -1;
                ++ans;
                revCnt ^= 1;
                diff[i + K] ^= 1;
            }
        }
        return ans;
    }
};