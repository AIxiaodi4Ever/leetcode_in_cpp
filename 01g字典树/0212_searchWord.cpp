struct TrieNode {
    string word;
    unordered_map<char, TrieNode *> children;
    TrieNode() {
        this->word = "";
    }
};

void insertWord(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

class Solution {
public:
    static constexpr int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m;
    int n;

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, vector<string>& ans) {
        char ch = board[x][y];
        if (!root->children.count(ch)) {
            return false;
        }
        root = root->children[ch];
        if (root->word.size() > 0) {
            ans.emplace_back(root->word);
            root->word = "";
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (board[nx][ny] != '#') {
                    dfs(board, nx, ny, root, ans);
                }
            }
        }
        board[x][y] = ch;

        return true;
    }

    // 原本使用了set去重
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode* root = new TrieNode();
        m = board.size();
        n = board[0].size();
        for (string & word : words) {
            insertWord(root, word);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
};