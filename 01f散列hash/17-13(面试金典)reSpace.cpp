/*
方法二：字符串哈希

预备知识

    字符串哈希：可参考「1392. 最长快乐前缀」官方题解中的「背景知识」。

思路和算法

我们使用字典树的目的是查找某一个串 sss 是否在一个串的集合 SSS 当中，并且当我们知道 sss 是否在 SSS 中之后，
可以快速的知道在 sss 后添加某一个新的字母得到的新串 s′s's′ 是否在 SSS 中，这个转移的过程是 O(1)O(1)O(1) 的。
这是我们采用字典树而放弃使用 HashMap 类容器的一个理由，这些容器不能实现 sss 到 s′s's′ 的 O(1)O(1)O(1) 转移，但字典树可以。

其实还用一种字符串哈希的方法也能实现 O(1)O(1)O(1) 的转移，就是「预备知识」中提到的 Rabin-Karp 方法。我们用这种方法替换字
典树，时间复杂度不变，空间复杂度可以优化到 O(n+q)O(n + q)O(n+q)，其中 nnn 为 sentencesentencesentence 中元素的个数，qqq 
为词典中单词的个数。

代码如下

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/re-space-lcci/solution/hui-fu-kong-ge-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    using LL = long long;

    static constexpr LL P = (1LL << 31) - 1;
    static constexpr LL BASE = 41;

    LL getHash(const string &s) {
        LL hashValue = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            hashValue = hashValue * BASE + s[i] - 'a' + 1;
            hashValue = hashValue % P;
        }
        return hashValue;
    }

    int respace(vector<string>& dictionary, string sentence) {
        unordered_set <LL> hashValues;
        for (const auto &word: dictionary) {
            hashValues.insert(getHash(word));
        }

        vector <int> f(sentence.size() + 1, sentence.size());

        f[0] = 0;
        for (int i = 1; i <= sentence.size(); ++i) {
            f[i] = f[i - 1] + 1;
            LL hashValue = 0;
            for (int j = i; j >= 1; --j) {
                int t = sentence[j - 1] - 'a' + 1;
                hashValue = hashValue * BASE + t;
                hashValue = hashValue % P;
                if (hashValues.find(hashValue) != hashValues.end()) {
                    f[i] = min(f[i], f[j - 1]);
                }
            }
        }

        return f[sentence.size()];
    }
};