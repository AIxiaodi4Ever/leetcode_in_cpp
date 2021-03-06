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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/divisor-game
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


// �ⷨ1���ҹ���
// ���Է���1ʱ��Alice����2ʱAliceʤ����3ʱAlice����4ʱAliceʤ
// ���Բ²�Alice�õ�ż��ʱ��ʤ��
// ������ѧ���ɷ�֤������֪N = 1��N = 2ʱ�����������N<=kʱ�����������N=k+1ʱ��
// 1.���k+1Ϊ��������xֻ��Ϊ�����������õ�һ��ż����bob���ɼ���bobʤ��alice����
// 2. ���k+1Ϊż������x����Ϊ������Ҳ����Ϊż�������Aliceѡ����������bob�õ�һ���������ɼ���bob����Aliceʤ
class Solution {
public:
    bool divisorGame(int N) 
    {
        return N % 2 == 0;
    }
};


// �ⷨ2����̬�滮
// ��dp(i)��ʾN=iʱAlice��ʤ���������֤��i��һ������x��ʹdp[i-x]�ذܣ�����ж�Alice��ʤ
// ��˴�ǰ����dp
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