class Solution {
public:
    int longestOnes(vector<int>& A, int K) 
    {
        int n = A.size();
        vector<int> preSum(n + 1);;
        for (int i = 1; i <= n; ++i)
        {
            preSum[i] = preSum[i - 1] + 1 - A[i - 1];
        }

        int ans = 0;
        for (int right = 1; right <= n; ++right)
        {
            // �����γ�������ҿ�����[left, right)��left=right���������
            // ��Ϊǰi������ǰ׺��������0~i-1
            int left = lower_bound(preSum.begin(), preSum.end(), preSum[right] - K) - preSum.begin();
            ans = max(ans, right - left);
        }

        return ans;
    }
};