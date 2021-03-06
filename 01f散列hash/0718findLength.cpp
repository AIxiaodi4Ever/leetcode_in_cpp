// �ⷨ3�����ֲ���+hash
/*
˼·���㷨

������� A �� B ��һ������Ϊ k �Ĺ��������飬��ô����һ���г���Ϊ j <= k �Ĺ��������顣�������ǿ���ͨ�����ֲ��ҵķ����ҵ����� k��
��Ϊ���Ż�ʱ�临�Ӷȣ��ڶ��ֲ��ҵ�ÿһ���У����ǿ��Կ���ʹ�ù�ϣ�ķ������ж����� A �� B ���Ƿ������ͬ�ض����ȵ������顣
ע�⵽������Ԫ��ֵС�� 100100100 ������ʹ�� Rabin-Karp �㷨�������н��й�ϣ������أ������ƶ�һ������ base����ô���� S �Ĺ�ϣֵΪ��
hash(S)=��i=0�OS�O?1base�OS�O?(i+1)��S[i]\mathrm{hash}(S) = \sum_{i=0}^{|S|-1} base^{|S|-(i+1)} \times S[i] hash(S)=i=0�ƨOS�O?1?base�OS�O?(i+1)��S[i]

�����˵�����ǰ� S ����һ������ base ���Ƶ��������Ϊ��λ���Ҳ�Ϊ��λ��������ʮ����ֵ����������Ĺ�ϣֵ���������ֵһ���ǳ���
��˻Ὣ������һ������ mod ȡģ��

������Ҫ��һ������ S? ��������г���Ϊ len �������еĹ�ϣֵʱ�����ǿ��������ƻ������ڵķ�����������ʱ���ڵõ���Щ�����еĹ�ϣֵ��
���磬������ǵ�ǰ�õ��� S[0:len] �Ĺ�ϣֵ��ϣ����� S[1:len+1] �Ĺ�ϣֵʱ�������������ʽ��
hash(S[1:len+1])=(hash(S[0:len])?baselen?1��S[0])��base+S[len]\mathrm{hash}(S[1:len+1]) = 
(\mathrm{hash}(S[0:len]) - base^{len-1} \times S[0]) \times base + S[len] hash(S[1:len+1])=(hash(S[0:len])?baselen?1��S[0])��base+S[len]

��������� Python ��ʾ����ķ�����A[i:j] ��ʾ���� A ������ i ������ j - 1 �ķ�Χ��Ӧ�������顣
��ʽ�ĺ���Ϊ��ɾȥ���λ S[0]������λ�Զ���һ�����������λ S[len]��

�ڶ��ֲ��ҵ�ÿһ���У�����ʹ�ù�ϣ��ֱ�洢��������������г���Ϊ len ��������Ĺ�ϣֵ�������ǵĹ�ϣֵ���бȶԣ���������д�����ͬ�Ĺ�ϣֵ��
����Ϊ�����д�����ͬ�������顣Ϊ�˷�ֹ��ϣ��ײ������Ҳ�����ڷ�������������Ĺ�ϣֵ���ʱ����һ��У�����Ǳ����Ƿ�ȷʵ��ͬ����ȷ����ȷ�ԡ�����
�����ڱ����к��ѷ�����ϣ��ײ�������ȥ��һ��У��Ĳ��֡�
���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/solution/zui-chang-zhong-fu-zi-shu-zu-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

class Solution {
public:
    const int mod = 1000000009;
    const int base = 113;
    
    // ʹ�ÿ����ݼ��� x^n % mod ��ֵ
    long long qPow(long long x, long long n) {
        long long ret = 1;
        while (n) {
            if (n & 1) {
                ret = ret * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return ret;
    }

    bool check(vector<int>& A, vector<int>& B, int len) {
        long long hashA = 0;
        for (int i = 0; i < len; i++) {
            hashA = (hashA * base + A[i]) % mod;
        }
        unordered_set<long long> bucketA;
        bucketA.insert(hashA);
        long long mult = qPow(base, len - 1);
        for (int i = len; i < A.size(); i++) {
            hashA = ((hashA - A[i - len] * mult % mod + mod) % mod * base + A[i]) % mod;
            bucketA.insert(hashA);
        }
        long long hashB = 0;
        for (int i = 0; i < len; i++) {
            hashB = (hashB * base + B[i]) % mod;
        }
        if (bucketA.count(hashB)) {
            return true;
        }
        for (int i = len; i < B.size(); i++) {
            hashB = ((hashB - B[i - len] * mult % mod + mod) % mod * base + B[i]) % mod;
            if (bucketA.count(hashB)) {
                return true;
            }
        }
        return false;
    }

    int findLength(vector<int>& A, vector<int>& B) {
        int left = 1, right = min(A.size(), B.size());
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (check(A, B, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};
