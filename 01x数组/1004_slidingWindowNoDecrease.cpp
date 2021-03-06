class Solution {
public:
    int longestOnes(vector<int>& A, int K) 
    {
        int n = A.size();
        // lsum��rsum�ֱ��ʾ��0~left-1����0~right-1�ķ�ת��ǰ׺��
        int left = 0, right = 0, lsum = 0, rsum = 0;
        int ans = 0;
        while (right < n)
        {
            rsum += (1 - A[right]);
            if (rsum - lsum > K)
            {
                lsum += (1 - A[left]);
                ++left;
            }
            ++right;
        }
        return right - left;
    }
};