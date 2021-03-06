class Solution {
public:
    /* 两个窗口，共享右端点，其中第一个窗口左端点left1表示以right结尾并且含有k个不同整数且窗口最长时的左端点 */
    /* 第二个窗口左端点left2表示以right结尾并且含有k-1个不同整数且窗口最长时的左端点                       */
    /* 可以证明以[left1, left2)为起点，right为终点的窗口一定只含有k个不同的整数                           */
    /* 因为数的大小不超过数组长度，所以时间空间复杂度均为O(N)                                             */
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        vector<int> num1(n + 1, 0), num2(n + 1, 0);
        int left1 = 0, left2 = 0, right = 0;
        int tot1 = 0, tot2 = 0;
        int ans = 0;
        while (right < n)
        {
            // 处理第一个窗口，即k个不同整数时对应最左边的left1
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

            // 处理第二个窗口，即k-1个不同整数时对应最左边的left2
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