struct TrieNode {
    int frequency = 0;
    TrieNode* child[26];

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }
};

class Solution {
private:
    TrieNode* root;

public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        root = new TrieNode();

        auto add = [&](const string& word) {
            TrieNode* cur = root;
            for (char ch: word) {
                if (!cur->child[ch - 'a']) {
                    cur->child[ch - 'a'] = new TrieNode();
                }
                cur = cur->child[ch - 'a'];
            }
            ++cur->frequency;
        };

        // �ڻ��ݵĹ�����ö�� puzzle �������Ӽ���ͳ�ƴ�
        // find(puzzle, required, cur, pos) ��ʾ puzzle ������ĸΪ required, ��ǰ�������ֵ����ϵ� cur �ڵ㣬����׼��ö�� puzzle �ĵ� pos ����ĸ�Ƿ�ѡ�񣨷����Ӽ��У�
        // find �����ķ���ֵ��Ϊ�յ׵�����
        function<int(const string&, char, TrieNode*, int)> find = [&](const string& puzzle, char required, TrieNode* cur, int pos) {
            // �������սڵ㣬���Ϸ������� 0
            if (!cur) {
                return 0;
            }
            // ���� puzzle ������ϣ������յ׵�����
            if (pos == 7) {
                return cur->frequency;
            }
            
            // ѡ��� pos ����ĸ
            int ret = find(puzzle, required, cur->child[puzzle[pos] - 'a'], pos + 1);

            // �� puzzle[pos] ��Ϊ����ĸʱ�����Բ�ѡ��� pos ����ĸ
            if (puzzle[pos] != required) {
                ret += find(puzzle, required, cur, pos + 1);
            }
            
            return ret;
        };
        
        for (string word: words) {
            // �� word �е���ĸ�����ֵ�������ȥ��
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
            // �����ֵ�����
            add(word);
        }

        vector<int> ans;
        for (string puzzle: puzzles) {
            char required = puzzle[0];
            sort(puzzle.begin(), puzzle.end());
            ans.push_back(find(puzzle, required, root, 0));
        }
        return ans;
    }
};