struct TrieNode {
    int frequency = 0;
    TrieNode* child[26];

    TrieNode()
    {
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
    }
};

class Solution {
private:
    TrieNode *root;
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) 
    {
        root = new TrieNode();

        // 向字典树添加字符串
        auto add = [&](const string& word) {
            TrieNode *cur = root;
            for (char ch : word)
            {
                if (!cur->child[ch - 'a'])
                    cur->child[ch - 'a'] = new TrieNode();
                cur = cur->child[ch - 'a'];
            }
            ++cur->frequency;
        };

        // 回溯枚举puzzle的每个子集（puzzle已经排序）
        // puzzle为当前谜面，required为谜面首字母，cur为当前遍历到的字典树节点，pos为谜面的当前位置
        // find的返回值即为当前谜面的答案数
        // lambda的引用捕获的是自己，因为lambda的匿名特性，不能隐式捕获自己
        function<int(const string&, char, TrieNode*, int)> find = [&](const string& puzzle, char required, TrieNode* cur, int pos)->int {
            // 遍历到空节点，说明该子序列不在字典树中
            if (cur == nullptr)
                return 0;
            
            // 枚举到了puzzle的尾后，回溯
            if (pos == 7)
                return cur->frequency;
            
            // 子序列包含位置pos的元素
            int ret = find(puzzle, required, cur->child[puzzle[pos] - 'a'], pos + 1);
            // 子序列不好含位置pos的元素(首字母除外)，因为puzzle已经排过序，所以不能用pos == 0作为条件
            if (puzzle[pos] != required)
                ret += find(puzzle, required, cur, pos + 1);
            
            return ret;
        };

        // 添加所有word到字典树
        for (string word : words)
        {
            // word排过序且没有重复元素
            // 因为unique只能将相邻的重复元素移到尾后，所以必须先排序，并且unique返回没有移动的最后元素的尾后迭代器
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
            add(word);
        }

        // 
        vector<int> ans;
        for (string puzzle : puzzles)
        {
            // puzzle的长度固定为7，且没有重复元素，所以不需要unique, earse
            char required = puzzle[0];
            sort(puzzle.begin(), puzzle.end());
            ans.push_back(find(puzzle, required, root, 0));
        }

        return ans;
    }
};