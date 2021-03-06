// 程序员面试金典 08.11.
/*解题思路
动态规划，背包问题。
这里重点讨论一下dp不同循环方式的含义。
题目中4种硬币n个数，因此循环有两种：
(1) n x 4的循环
(2) 4 x n的循环
对于(1)n x 4的循环，表示的含义是，遍历每一个数字，都可以从4种币值中选取（类似DFS中不现实硬币种类），因此结果中相同硬币的不同顺序都进行统计。
对于(2)4 x n的循环，表示的含义是，遍历每一种币值，用来表示所有数字时得到的种类数（类似DFS中限制可用硬币的种类），因此结果中不会出现不同顺序的结果。
本质上，dp外层循环对应的是DFS的一次调用。
本题题意不考虑不同硬币顺序，因此使用4 x n的模型解决本问题。

作者：wolly
链接：https://leetcode-cn.com/problems/coin-lcci/solution/shi-yong-dong-tai-gui-hua-jie-jue-mian-shi-ti-0811/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int coins[4] = {1, 5, 10, 25};

//【算法思路】dp。
int waysToChange(int n){
    int *dp = (int *)calloc(n + 1, sizeof(int));

    dp[0] = 1;

    for(int i = 0; i < 4; i++) {
        int coin = coins[i];

        for(int j = 1; j <= n; j++) {
            if(j - coin >= 0) {
                dp[j] = (dp[j] + dp[j - coin]) % 1000000007;
            }
        }
    }

    return dp[n];
}