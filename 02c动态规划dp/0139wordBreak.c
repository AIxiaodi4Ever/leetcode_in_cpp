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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路：动态规划
// 1. 用dp[i]表示前i个字母能否被拆分成若干字典单词，从前往后考虑转移方程；
// 2. 首先另dp[0] = true;表示空字符合法的边界条件，其他dp初始化为false，每次判断dp[i]是否合法；
// 3. dp[i]合法的条件是，dp[i]的前j个字符合法且第j+1到第i个字符也合法，只要判断出某一个j使得dp[i]合法，
// 则判断下一个i+1是否合法；
// 4. 题解使用hash表，这里使用strcmp和strcat进行判断，如果第j+1到第i个字母的长度超过字典里最长单词的长度，则结束枚举；

void comb_alpha(char *temp, char *s, int j, int i)
{
    int index = 0;
    for (; j < i; j++)
    {
        temp[index++] = s[j];
    }
    temp[index] = '\0';
}

// 假设字母全部小写
bool judge_rem(char **wordDict, int wordDictSize, char *temp)
{
    for (int i = 0; i < wordDictSize; i++)
    {
        // 字符串相等返回0
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
    // 空字符为true
    dp[0] = true;
    // 记录字典中单词的最大长度
    for (int i = 0; i < wordDictSize; i++)
    {
        if (strlen(wordDict[i]) > maxLength)
        {
            maxLength = strlen(wordDict[i]);
        }
    }

    // 记录第j+1到第i个字母组成的字符串
    char *temp = (char *)malloc((maxLength + 1) * sizeof(char));

    // 循环计算dp[i]
    for (int i = 1; i <= sLength; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if ((i - j) > maxLength)
            {
                break;
            }

            // 将第j+1到第i个字母组合成字符串
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