// leetcode: 139
// description:
/* 
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:
    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/word-break
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·����̬�滮
// 1. ��dp[i]��ʾǰi����ĸ�ܷ񱻲�ֳ������ֵ䵥�ʣ���ǰ������ת�Ʒ��̣�
// 2. ������dp[0] = true;��ʾ���ַ��Ϸ��ı߽�����������dp��ʼ��Ϊfalse��ÿ���ж�dp[i]�Ƿ�Ϸ���
// 3. dp[i]�Ϸ��������ǣ�dp[i]��ǰj���ַ��Ϸ��ҵ�j+1����i���ַ�Ҳ�Ϸ���ֻҪ�жϳ�ĳһ��jʹ��dp[i]�Ϸ���
// ���ж���һ��i+1�Ƿ�Ϸ���
// 4. ���ʹ��hash������ʹ��strcmp��strcat�����жϣ������j+1����i����ĸ�ĳ��ȳ����ֵ�������ʵĳ��ȣ������ö�٣�

void comb_alpha(char *temp, char *s, int j, int i)
{
    int index = 0;
    for (; j < i; j++)
    {
        temp[index++] = s[j];
    }
    temp[index] = '\0';
}

// ������ĸȫ��Сд
bool judge_rem(char **wordDict, int wordDictSize, char *temp)
{
    for (int i = 0; i < wordDictSize; i++)
    {
        // �ַ�����ȷ���0
        if (!strcmp(temp, wordDict[i]))
        {
            return true;
        }
    }
    return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize)
{
    if (s == NULL)
    {
        return true;
    }

    unsigned int maxLength = 0;
    const unsigned int sLength = strlen(s);
    bool dp[sLength + 1];

    memset(dp, 0, sizeof(dp));
    // ���ַ�Ϊtrue
    dp[0] = true;
    // ��¼�ֵ��е��ʵ���󳤶�
    for (int i = 0; i < wordDictSize; i++)
    {
        if (strlen(wordDict[i]) > maxLength)
        {
            maxLength = strlen(wordDict[i]);
        }
    }

    // ��¼��j+1����i����ĸ��ɵ��ַ���
    char *temp = (char *)malloc((maxLength + 1) * sizeof(char));

    // ѭ������dp[i]
    for (int i = 1; i <= sLength; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if ((i - j) > maxLength)
            {
                break;
            }

            // ����j+1����i����ĸ��ϳ��ַ���
            comb_alpha(temp, s, j, i);

            if (dp[j] && judge_rem(wordDict, wordDictSize, temp))
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[sLength];
}