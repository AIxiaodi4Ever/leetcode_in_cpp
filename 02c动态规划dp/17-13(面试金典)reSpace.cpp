typedef struct Trie {
    struct Trie* next[26];
    bool isEnd;
} Trie;

void init(Trie** p) {
    *p = (Trie*)malloc(sizeof(Trie));
    (*p)->isEnd = false;
    memset((*p)->next, NULL, sizeof((*p)->next));
}

void insert(Trie* curPos, char* s) {
    int len = strlen(s);
    for (int i = len - 1; i >= 0; --i) {
        int t = s[i] - 'a';
        if (curPos->next[t] == NULL) {
            init(&curPos->next[t]);
        }
        curPos = curPos->next[t];
    }
    curPos->isEnd = true;
}

int respace(char** dictionary, int dictionarySize, char* sentence) {
    int n = strlen(sentence), inf = 0x3f3f3f3f;

    Trie* root;
    init(&root);
    for (int i = 0; i < dictionarySize; i++) {
        insert(root, dictionary[i]);
    }
    int dp[n + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;

        Trie* curPos = root;
        for (int j = i; j >= 1; --j) {
            int t = sentence[j - 1] - 'a';
            if (curPos->next[t] == NULL) {
                break;
            } else if (curPos->next[t]->isEnd) {
                dp[i] = fmin(dp[i], dp[j - 1]);
            }
            if (dp[i] == 0) {
                break;
            }
            curPos = curPos->next[t];
        }
    }
    return dp[n];
}
