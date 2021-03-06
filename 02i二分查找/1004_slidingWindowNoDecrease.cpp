class Solution {
public:
    int longestOnes(vector<int>& A, int K) 
    {
        int n = A.size();
        // lsum与rsum分别表示从0~left-1及从0~right-1的反转后前缀和
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