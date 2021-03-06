class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) 
    {
        int n = A.size();
        int num = 0;
        vector<bool> ans(n);
        for (int i = 0; i < n; ++i)
        {
            num = (num<<1) + A[i];
            num %= 5;
            if (num == 0)
                ans[i] = true;
        }
        return ans;
    }
};