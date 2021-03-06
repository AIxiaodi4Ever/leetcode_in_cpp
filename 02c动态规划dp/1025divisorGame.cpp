// leetcode:1025
/*
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:
    Choosing any x with 0 < x < N and N % x == 0.
    Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.
Return True if and only if Alice wins the game, assuming both players play optimally.

Example 1:
Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

Example 2:
Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.

Note:
    1 <= N <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divisor-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 解法1：找规律
// 可以发现1时，Alice负，2时Alice胜利，3时Alice负，4时Alice胜
// 可以猜测Alice拿到偶数时必胜；
// 利用数学归纳法证明，已知N = 1即N = 2时假设成立，设N<=k时假设成立，则N=k+1时，
// 1.如果k+1为奇数，则x只能为奇数，相减后得到一个偶数给bob，由假设bob胜，alice负。
// 2. 如果k+1为偶数，则x可以为奇数，也可以为偶数，如果Alice选择奇数，则bob得到一个奇数，由假设bob负，Alice胜
class Solution {
public:
    bool divisorGame(int N) 
    {
        return N % 2 == 0;
    }
};


// 解法2：动态规划
// 设dp(i)表示N=i时Alice的胜负，如果能证明i的一个因数x，使dp[i-x]必败，则可判断Alice必胜
// 因此从前往后dp
class Solution {
public:
    bool divisorGame(int N) 
    {
        vector<bool> dp(N + 1, false);
        dp[1] = false;
        dp[2] = true;
        for (int i = 3; i <= N; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                if (i % j == 0 && !dp[i - j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};