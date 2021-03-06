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
                // i-K����ת��������ԭ���������diff[i]-1�����������ֱ���޸�revCnt
                // ��ԭ���飬���ûҪ����Բ�д
                revCnt ^= 1;
                A[i - K] -= 2;  
            }
            if (A[i] == revCnt) // A[i] ^ revCnt == 0;
            {
                if (i + K > n)
                    return -1;
                ++ans;
                revCnt ^= 1;
                A[i] += 2;  // ��¼��λ�ñ���ת��  
            }
        }
        return ans;
    }
};