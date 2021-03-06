// 动态规划+字典树(trie树)
/*
    设dp[i]表示前i个字符中未识别的字符个数，从前往后计算dp;
    如果从第j个字符到第i个字符在字典中，即sentence[j-1]到sentence[i-1]在字典中;
    则:
        dp[i] = fmin(dp[i], dp[j-1]);
    否则：
        dp[i] = dp[i-1] + 1;
    
    将字典中的单词倒叙插入字典树，计算dp时倒叙检查sentence[j-1]到sentence[i-1]是否在字典树中；
    使用字典树的好处是，如果某个后缀不是字典树任何单词的后缀，则可以直接退出，计算下一个dp[i];
    hash表则会进行没必要的枚举；
*/
// 0 <= len(sentence) <= 1000
#define MAX 1001 

typedef struct Trie {
    struct Trie *next[26];
    bool isEnd;
}Trie;

// 传递 **p是因为调用init时传递的是NULL指针，给p分配存储空间后，原始的实参指针仍为NULL；
void init(Trie **p)
{
    *p = (Trie *)malloc(sizeof(Trie));
    (*p)->isEnd = false;
    memset((*p)->next, NULL, sizeof((*p)->next));
}

void insert(Trie *curChar, char *s)
{
    int len = strlen(s);
    // 倒叙插入，i递减；
    for (int i = len - 1; i >= 0; --i)
    {
        int t = s[i] - 'a';
        if (curChar->next[t] == NULL)
        {
            init(&curChar->next[t]);
        }
        curChar = curChar->next[t];
    }
    curChar->isEnd = true;
}

int respace(char** dictionary, int dictionarySize, char* sentence) 
{
    int len_sen = strlen(sentence);
    int *dp = (int *)malloc(sizeof(int) * (len_sen + 1));
    memset(dp, MAX, sizeof(int) * (len_sen + 1));

    Trie *root;
    // 传递的是root的地址
    init(&root);
    for (int i = 0; i < dictionarySize; ++i)
    {
        insert(root, dictionary[i]);
    }

    dp[0] = 0;
    for (int i = 1; i <= len_sen; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        Trie *curChar = root;
        // 倒叙查询
        for (int j = i; j > 0; --j)
        {
            int t = sentence[j - 1] - 'a';
            if (curChar->next[t] == NULL)
                break;
            // 条件是curChar->next[t]->isEnd
            else if (curChar->next[t]->isEnd)
            {
                dp[i] = fmin(dp[i], dp[j - 1]);
            }
            // 算出未识别的字符数为0，则可以提前退出，计算下一个dp[i]
            if (dp[i] == 0)
                break;
            curChar = curChar->next[t];
        }
    }
    return dp[len_sen];
}