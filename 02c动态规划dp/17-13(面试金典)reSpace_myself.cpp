// ��̬�滮+�ֵ���(trie��)
/*
    ��dp[i]��ʾǰi���ַ���δʶ����ַ���������ǰ�������dp;
    ����ӵ�j���ַ�����i���ַ����ֵ��У���sentence[j-1]��sentence[i-1]���ֵ���;
    ��:
        dp[i] = fmin(dp[i], dp[j-1]);
    ����
        dp[i] = dp[i-1] + 1;
    
    ���ֵ��еĵ��ʵ�������ֵ���������dpʱ������sentence[j-1]��sentence[i-1]�Ƿ����ֵ����У�
    ʹ���ֵ����ĺô��ǣ����ĳ����׺�����ֵ����κε��ʵĺ�׺�������ֱ���˳���������һ��dp[i];
    hash��������û��Ҫ��ö�٣�
*/
// 0 <= len(sentence) <= 1000
#define MAX 1001 

typedef struct Trie {
    struct Trie *next[26];
    bool isEnd;
}Trie;

// ���� **p����Ϊ����initʱ���ݵ���NULLָ�룬��p����洢�ռ��ԭʼ��ʵ��ָ����ΪNULL��
void init(Trie **p)
{
    *p = (Trie *)malloc(sizeof(Trie));
    (*p)->isEnd = false;
    memset((*p)->next, NULL, sizeof((*p)->next));
}

void insert(Trie *curChar, char *s)
{
    int len = strlen(s);
    // ������룬i�ݼ���
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
    // ���ݵ���root�ĵ�ַ
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
        // �����ѯ
        for (int j = i; j > 0; --j)
        {
            int t = sentence[j - 1] - 'a';
            if (curChar->next[t] == NULL)
                break;
            // ������curChar->next[t]->isEnd
            else if (curChar->next[t]->isEnd)
            {
                dp[i] = fmin(dp[i], dp[j - 1]);
            }
            // ���δʶ����ַ���Ϊ0���������ǰ�˳���������һ��dp[i]
            if (dp[i] == 0)
                break;
            curChar = curChar->next[t];
        }
    }
    return dp[len_sen];
}