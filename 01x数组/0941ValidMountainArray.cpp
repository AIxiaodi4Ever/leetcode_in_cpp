class Solution {
public:
    bool validMountainArray(vector<int>& A) noexcept
    {
        int i = 0;
        int n = A.size();
        while (i + 1 < n && A[i] < A[i + 1])
            ++i;
        if (i == 0 || i == n - 1)
            return false;
        while (i + 1 < n && A[i] > A[i + 1])
            ++i;
        return i == n - 1;
    }
};