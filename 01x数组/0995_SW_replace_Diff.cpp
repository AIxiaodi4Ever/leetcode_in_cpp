class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) 
    {
        int n = A.size();
        int ans = 0, revCnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i >= K && A[i - K] > 1)
            {
                // i-K被反转过，所以原差分数组中diff[i]-1，在这里可以直接修改revCnt
                // 复原数组，如果没要求可以不写
                revCnt ^= 1;
                A[i - K] -= 2;  
            }
            if (A[i] == revCnt) // A[i] ^ revCnt == 0;
            {
                if (i + K > n)
                    return -1;
                ++ans;
                revCnt ^= 1;
                A[i] += 2;  // 记录该位置被反转过  
            }
        }
        return ans;
    }
};