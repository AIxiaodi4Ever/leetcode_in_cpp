class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) 
    {
        vector<int> ans(A.size());
        int i = 0;
        for (int x : A)
        {
            if (x % 2 == 0)
            {
                ans[i] = x;
                i += 2;
            }
        }
        i = 1;
        for (int x : A)
        {
            if (x % 2 == 1)
            {
                ans[i] = x;
                i += 2;
            }
        }
        return ans;
    }
};