// ��Ϊ����A�ܴ����Բ���ֱ����ӣ�ֻ����λ���
// �ȵõ���λ����push
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) 
    {
        vector<int> ans;
        int n = A.size();
        for (int i = n - 1; i >= 0; --i)
        {
            int sum = A[i] + K % 10;
            K /= 10;
            if (sum >= 10)
            {
                ++K;
                sum -= 10;
            }
            ans.push_back(sum);
        }
        while (K > 0)
        {
            int digit = K % 10;
            K /= 10;
            ans.push_back(digit);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};