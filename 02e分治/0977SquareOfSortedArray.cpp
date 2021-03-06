class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        int n = A.size();
        vector<int> ans(n);

        int left = 0, right = n - 1, pos = n - 1;
        while (left <= right)
        {
            int ls = A[left] * A[left], rs = A[right] * A[right];
            if (ls > rs)
            {
                ans[pos] = ls;
                ++left;
            }
            else
            {
                ans[pos] = rs;
                --right;
            }
            --pos;
        }
        return ans;
    }
};