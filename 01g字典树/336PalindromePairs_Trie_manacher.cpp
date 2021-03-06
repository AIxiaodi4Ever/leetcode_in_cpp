struct Trie {
    struct node {
        int ch[26];
        int flag;
        node() {
            flag = -1;
            memset(ch, 0, sizeof(ch));
        }
    };

    vector<node> tree;

    Trie() { tree.emplace_back(); }

    void insert(string& s, int id) {
        int len = s.length(), add = 0;
        for (int i = 0; i < len; i++) {
            int x = s[i] - 'a';
            if (!tree[add].ch[x]) {
                tree.emplace_back();
                tree[add].ch[x] = tree.size() - 1;
            }
            add = tree[add].ch[x];
        }
        tree[add].flag = id;
    }

    vector<int> query(string& s) {
        int len = s.length(), add = 0;
        vector<int> ret(len + 1, -1);
        for (int i = 0; i < len; i++) {
            ret[i] = tree[add].flag;
            int x = s[i] - 'a';
            if (!tree[add].ch[x]) {
                return ret;
            }
            add = tree[add].ch[x];
        }
        ret[len] = tree[add].flag;
        return ret;
    }
};

class Solution {
public:
    vector<pair<int, int>> manacher(string& s) {
        int n = s.length();
        string tmp = "#";
        tmp += s[0];
        for (int i = 1; i < n; i++) {
            tmp += '*';
            tmp += s[i];
        }
        tmp += '!';
        int m = n * 2;
        vector<int> len(m);
        vector<pair<int, int>> ret(n);
        int p = 0, maxn = -1;
        for (int i = 1; i < m; i++) {
            // 这里:后面不是1，是因为***回文半径不包括该字符本身***(包含该字符本身则最小的回文半径为1)
            len[i] = maxn >= i ? min(len[2 * p - i], maxn - i) : 0;
            while (tmp[i - len[i] - 1] == tmp[i + len[i] + 1]) {
                len[i]++;
            }
            if (i + len[i] > maxn) {
                p = i, maxn = i + len[i];
            }
            // 位置0是#，所以如果到达位置1说明从1到i+len[i]是回文
            // 同时说明，原始字符串位置0到(i + len[i] ) / 2的前缀是回文
            // (i + len[i]) / 2的大小正好是原始前缀回文数的一半-1，正好是前缀的最后一个字母的索引
            if (i - len[i] == 1) {
                ret[(i + len[i]) / 2].first = 1;
            }
            // 处理后的字符串位置m是！位置m-1是最后一个字符，且len的大小只有m
            // 处理后的字符串从(i - len[i])到m-1为回文，说明原始字符串从(i-len[i])/2到最后有一个字符的后缀为回文
            // m-1一定为奇数，所以如果i+len[i]为奇数，则i-len[i]也一定为奇数，(i-len[i])/2就是原始字符串中相同字符对应的索引
            if (i + len[i] == m - 1) {
                ret[(i - len[i]) / 2].second = 1;
            }
        }
        return ret;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie1, trie2;

        int n = words.size();
        for (int i = 0; i < n; i++) {
            trie1.insert(words[i], i);
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            trie2.insert(tmp, i);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            // rec的索引为字符串中字符的下标
            const vector<pair<int, int>>& rec = manacher(words[i]);

            // id的索引意义为字符串中字符的数量
            const vector<int>& id1 = trie2.query(words[i]);
            // 这里对字符串又反转了一次，所以可以用正向建立的字典树验证k的后缀的反转
            reverse(words[i].begin(), words[i].end());
            const vector<int>& id2 = trie1.query(words[i]);

            int m = words[i].size();

            // 这个if是处理将字符串分解为：空字符串和它本身的情况
            // 不在后面处理，正好避免了重复，，
            int all_id = id1[m];
            if (all_id != -1 && all_id != i) {
                ret.push_back({i, all_id});
            }
            for (int j = 0; j < m; j++) {
                if (rec[j].first) {
                    int left_id = id2[m - j - 1];
                    if (left_id != -1 && left_id != i) {
                        ret.push_back({left_id, i});
                    }
                }
                if (rec[j].second) {
                    int right_id = id1[j];
                    if (right_id != -1 && right_id != i) {
                        ret.push_back({i, right_id});
                    }
                }
            }
        }
        return ret;
    }
};