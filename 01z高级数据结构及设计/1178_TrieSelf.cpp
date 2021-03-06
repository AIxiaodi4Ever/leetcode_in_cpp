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

        // ���ֵ�������ַ���
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

        // ����ö��puzzle��ÿ���Ӽ���puzzle�Ѿ�����
        // puzzleΪ��ǰ���棬requiredΪ��������ĸ��curΪ��ǰ���������ֵ����ڵ㣬posΪ����ĵ�ǰλ��
        // find�ķ���ֵ��Ϊ��ǰ����Ĵ���
        // lambda�����ò�������Լ�����Ϊlambda���������ԣ�������ʽ�����Լ�
        function<int(const string&, char, TrieNode*, int)> find = [&](const string& puzzle, char required, TrieNode* cur, int pos)->int {
            // �������սڵ㣬˵���������в����ֵ�����
            if (cur == nullptr)
                return 0;
            
            // ö�ٵ���puzzle��β�󣬻���
            if (pos == 7)
                return cur->frequency;
            
            // �����а���λ��pos��Ԫ��
            int ret = find(puzzle, required, cur->child[puzzle[pos] - 'a'], pos + 1);
            // �����в��ú�λ��pos��Ԫ��(����ĸ����)����Ϊpuzzle�Ѿ��Ź������Բ�����pos == 0��Ϊ����
            if (puzzle[pos] != required)
                ret += find(puzzle, required, cur, pos + 1);
            
            return ret;
        };

        // �������word���ֵ���
        for (string word : words)
        {
            // word�Ź�����û���ظ�Ԫ��
            // ��Ϊuniqueֻ�ܽ����ڵ��ظ�Ԫ���Ƶ�β�����Ա��������򣬲���unique����û���ƶ������Ԫ�ص�β�������
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
            add(word);
        }

        // 
        vector<int> ans;
        for (string puzzle : puzzles)
        {
            // puzzle�ĳ��ȹ̶�Ϊ7����û���ظ�Ԫ�أ����Բ���Ҫunique, earse
            char required = puzzle[0];
            sort(puzzle.begin(), puzzle.end());
            ans.push_back(find(puzzle, required, root, 0));
        }

        return ans;
    }
};