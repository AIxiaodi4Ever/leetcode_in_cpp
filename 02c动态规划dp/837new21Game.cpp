/* leetcode:837 */
/*
Alice plays the following game, loosely based on the card game "21".
Alice starts with 0 points, and draws numbers while she has less than K points.  
During each draw, she gains an integer number of points randomly from the range 
[1, W], where W is an integer.  Each draw is independent and the outcomes have 
equal probabilities.
Alice stops drawing numbers when she gets K or more points.  What is the probability 
that she has N or less points?

Example 1:
Input: N = 10, K = 1, W = 10
Output: 1.00000
Explanation:  Alice gets a single card, then stops.

Example 2:
Input: N = 6, K = 1, W = 10
Output: 0.60000
Explanation:  Alice gets a single card, then stops.
In 6 out of W = 10 possibilities, she is at or below N = 6 points.

Example 3:
Input: N = 21, K = 17, W = 10
Output: 0.73278

Note:
    0 <= K <= N <= 10000
    1 <= W <= 10000
    Answers will be accepted as correct if they are within 10^-5 of the correct answer.
    The judging time limit has been reduced for this question.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/new-21-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路
// 初始为x时获胜的概率为dp[x]，当 K<=x<=min(N, K+W-1)时，dp[x]=1, 当x>=min(N, K+W-1)时，dp[x]=0;
// 大于N时很好理解，大于K+W-1时是因为取不到;
// 当 0<=x<K时，dp[x] = (dp[x+1] +...+dp[x+W])/W;
// 根据上面状态转移方程，写出的程序时间复杂度为O(N+KW)，超出时间限制，可以对其简化;
// 可以看出，差分运算：
// dp[x] - dp[x+1] = (dp[x+1] - dp[x+W+1]) / W;
// 所以dp[x] = dp[x+1] + (dp[x+1] - dp[x+W+1]) / W;
// 以上仅仅适用于x < K - 1的情况，当x = K - 1时，dp[K-1] = (dp[K] + ... + dp[K+W-1]) / W;
// 因为当 K<=x<=min(N, K+W-1)时，dp[x]=1,上式等价于：dp[k-1] = (min(N,K+W-1) - K + 1) / W; 即dp[k-1] = min(N-K+1,W)/W;

#define min(x,y) (((x) > (y))?(y):(x))

double new21Game(int N, int K, int W)
{
    int min_num;
    if (K == 0)
        return 1.0;

    double *dp = (double *)calloc(K + W, sizeof(double));

    min_num = min(N, K + W - 1);
    for (int i = K; i <= min_num; i++)
    {
        dp[i] = 1;
    }

    dp[K - 1] = (double)(min_num - K + 1) / W;

    for (int i = K - 2; i >= 0; i--)
    {
        dp[i] = dp[i + 1] - (dp[i + W + 1] - dp[i + 1]) / W;
    }

    return dp[0];
}