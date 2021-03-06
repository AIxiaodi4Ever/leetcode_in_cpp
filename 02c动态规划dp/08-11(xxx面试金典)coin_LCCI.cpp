// ����Ա���Խ�� 08.11.
/*����˼·
��̬�滮���������⡣
�����ص�����һ��dp��ͬѭ����ʽ�ĺ��塣
��Ŀ��4��Ӳ��n���������ѭ�������֣�
(1) n x 4��ѭ��
(2) 4 x n��ѭ��
����(1)n x 4��ѭ������ʾ�ĺ����ǣ�����ÿһ�����֣������Դ�4�ֱ�ֵ��ѡȡ������DFS�в���ʵӲ�����ࣩ����˽������ͬӲ�ҵĲ�ͬ˳�򶼽���ͳ�ơ�
����(2)4 x n��ѭ������ʾ�ĺ����ǣ�����ÿһ�ֱ�ֵ��������ʾ��������ʱ�õ���������������DFS�����ƿ���Ӳ�ҵ����ࣩ����˽���в�����ֲ�ͬ˳��Ľ����
�����ϣ�dp���ѭ����Ӧ����DFS��һ�ε��á�
�������ⲻ���ǲ�ͬӲ��˳�����ʹ��4 x n��ģ�ͽ�������⡣

���ߣ�wolly
���ӣ�https://leetcode-cn.com/problems/coin-lcci/solution/shi-yong-dong-tai-gui-hua-jie-jue-mian-shi-ti-0811/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int coins[4] = {1, 5, 10, 25};

//���㷨˼·��dp��
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