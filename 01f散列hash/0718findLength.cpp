// 解法3，二分查找+hash
/*
思路及算法

如果数组 A 和 B 有一个长度为 k 的公共子数组，那么它们一定有长度为 j <= k 的公共子数组。这样我们可以通过二分查找的方法找到最大的 k。
而为了优化时间复杂度，在二分查找的每一步中，我们可以考虑使用哈希的方法来判断数组 A 和 B 中是否存在相同特定长度的子数组。
注意到序列内元素值小于 100100100 ，我们使用 Rabin-Karp 算法来对序列进行哈希。具体地，我们制定一个素数 base，那么序列 S 的哈希值为：
hash(S)=∑i=0∣S∣?1base∣S∣?(i+1)×S[i]\mathrm{hash}(S) = \sum_{i=0}^{|S|-1} base^{|S|-(i+1)} \times S[i] hash(S)=i=0∑∣S∣?1?base∣S∣?(i+1)×S[i]

形象地说，就是把 S 看成一个类似 base 进制的数（左侧为高位，右侧为低位），它的十进制值就是这个它的哈希值。由于这个值一般会非常大，
因此会将它对另一个素数 mod 取模。

当我们要在一个序列 S? 中算出所有长度为 len 的子序列的哈希值时，我们可以用类似滑动窗口的方法，在线性时间内得到这些子序列的哈希值。
例如，如果我们当前得到了 S[0:len] 的哈希值，希望算出 S[1:len+1] 的哈希值时，有下面这个公式：
hash(S[1:len+1])=(hash(S[0:len])?baselen?1×S[0])×base+S[len]\mathrm{hash}(S[1:len+1]) = 
(\mathrm{hash}(S[0:len]) - base^{len-1} \times S[0]) \times base + S[len] hash(S[1:len+1])=(hash(S[0:len])?baselen?1×S[0])×base+S[len]

这里借用了 Python 表示数组的方法，A[i:j] 表示数组 A 中索引 i 到索引 j - 1 的范围对应的子数组。
公式的含义为，删去最高位 S[0]，其余位自动进一，并补上最低位 S[len]。

在二分查找的每一步中，我们使用哈希表分别存储这两个数组的所有长度为 len 的子数组的哈希值，将它们的哈希值进行比对，如果两序列存在相同的哈希值，
则认为两序列存在相同的子数组。为了防止哈希碰撞，我们也可以在发现两个子数组的哈希值相等时，进一步校验它们本身是否确实相同，以确保正确性。但该
方法在本题中很难发生哈希碰撞，因此略去进一步校验的部分。
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/solution/zui-chang-zhong-fu-zi-shu-zu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    const int mod = 1000000009;
    const int base = 113;
    
    // 使用快速幂计算 x^n % mod 的值
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
