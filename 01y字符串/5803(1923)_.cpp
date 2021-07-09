class Solution {
private:
    // 理论上mod需要大于10^10（子数组数量的平方）
    // 因此再C++中需要long long类型
    // 在进行hash运算时，中间值会超出long long类型的限制
    // 采取折中的方法，对mod1及mod2分别取模，得到一个二元组
    // 这本质上与对mod1 * mod2取模是一致的，选择mod1=10^9+7，mod2=10^9+9
    // 这两个数都是质数，乘积约为10^18，远大于10^10
    static constexpr int mod1 = 1e9 + 7;
    static constexpr int mod2 = 1e9 + 9;

    // 得到的hash是一个二元组，C++默认不支持将pair放入哈希表，需自行实现哈希函数
    struct pairhash {
        size_t operator() (const pair<int, int>& p) const {
            auto fn = hash<int>();
            return (fn(p.first) << 16) ^ fn(p.second);
        }
    };

    using LL = long long;

public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        // 本题中数组元素的范围是(0~10^5]
        // 因此我们在[10^6, 10^7]的范围内随机选择进制
        // 为了更减少冲突，对mod1和mod2分别选取base1和base2
        mt19937 gen(random_device{}());     // 类后面加{}相当于调用默认构造函数生成了一个临时类对象
        uniform_int_distribution<int> dis(1e6, 1e7);
        int base1 = dis(gen);
        int base2 = dis(gen);

        int m = paths.size();
        // 确定二分查找上下界
        int left = 1, right = min_element(paths.begin(), paths.end(), [](const auto& p1, const auto& p2){ return p1.size() < p2.size();})->size();
        while (left <= right) {
            int len = left + (right - left) / 2;
            // 预处理 mult1=base1^len, mult2 = base2^len
            int mult1 = 1, mult2 = 1;
            for (int i = 0; i < len; ++i) {
                mult1 = (LL)mult1 * base1 % mod1;
                mult2 = (LL)mult2 * base2 % mod2;
            }

            // 上一数组的哈希表
            unordered_set<pair<int, int>, pairhash> s;  
            bool check = true;
            for (int i = 0; i < m; ++i) {
                int hash1 = 0, hash2 = 0;
                // 计算首个长度为len的子数组的哈希值
                for (int j = 0; j < len; ++j) {
                    hash1 = ((LL)hash1 * base1 + paths[i][j]) % mod1;
                    hash2 = ((LL)hash2 * base2 + paths[i][j]) % mod2;
                }
                // 当前数组的哈希表
                unordered_set<pair<int, int>, pairhash> t;     
                // 只有当前遍历的是第一个数组，或上一数组的哈希表中包含该二元组
                // 才将二元组加入当前数组的哈希表
                if (i == 0 || s.count({hash1, hash2})) {
                    t.emplace(hash1, hash2);
                }

                // 滚动哈希计算后续长度为len的子数组的哈希值
                for (int j = len; j < paths[i].size(); ++j) {
                    hash1 = (((LL)hash1 * base1 % mod1 - (LL)paths[i][j - len] * mult1 + paths[i][j]) % mod1 + mod1) % mod1;
                    hash2 = (((LL)hash2 * base2 % mod2 - (LL)paths[i][j - len] * mult2 + paths[i][j]) % mod2 + mod2) % mod2;
                    if (i == 0 || s.count({hash1, hash2})) {
                        t.emplace(hash1, hash2);
                    }
                }

                if (t.empty()) {
                    check = false;
                    break;
                }

                s = move(t);
            }

            if (check) {
                left = len + 1;
            }
            else {
                right = len - 1;
            }
        }
        return left - 1;
    }
};

