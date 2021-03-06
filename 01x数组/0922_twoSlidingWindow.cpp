class Solution {
public:
    /* �������ڣ������Ҷ˵㣬���е�һ��������˵�left1��ʾ��right��β���Һ���k����ͬ�����Ҵ����ʱ����˵� */
    /* �ڶ���������˵�left2��ʾ��right��β���Һ���k-1����ͬ�����Ҵ����ʱ����˵�                       */
    /* ����֤����[left1, left2)Ϊ��㣬rightΪ�յ�Ĵ���һ��ֻ����k����ͬ������                           */
    /* ��Ϊ���Ĵ�С���������鳤�ȣ�����ʱ��ռ临�ӶȾ�ΪO(N)                                             */
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        vector<int> num1(n + 1, 0), num2(n + 1, 0);
        int left1 = 0, left2 = 0, right = 0;
        int tot1 = 0, tot2 = 0;
        int ans = 0;
        while (right < n)
        {
            // �����һ�����ڣ���k����ͬ����ʱ��Ӧ����ߵ�left1
            if (!num1[A[right]])
                ++tot1;
            ++num1[A[right]];
            while (tot1 > K)
            {
                --num1[A[left1]];
                if (!num1[A[left1]])
                    --tot1;
                ++left1;
            }

            // ����ڶ������ڣ���k-1����ͬ����ʱ��Ӧ����ߵ�left2
            if (!num2[A[right]])
                ++tot2;
            ++num2[A[right]];
            while (tot2 > K - 1)
            {
                --num2[A[left2]];
                if (!num2[A[left2]])
                    --tot2;
                ++left2;
            }
            ans += left2 - left1;
            ++right;
        }
        return ans;
    }
};