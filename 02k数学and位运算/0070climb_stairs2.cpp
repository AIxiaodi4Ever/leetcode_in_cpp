// leetcode:070
// 动态规划、矩阵快速幂或通项公式

// 循环的时间复杂度为O(n)，略慢
// 解题思路2：矩阵快速幂
/*
 * [1 1] [ f(n) ]  = [f(n) + f(n-1)]  = [1 1]^n [f(1)] = [f(n+1)]
 * [1 0] [f(n-1)]    [    f(n)     ]    [1 0]   [f(0)]   [ f(n) ]
 * 
*/
// 上面是2x2的矩阵
// 这题官方题解方法二很有趣
// 直接计算n次方的时间复杂度仍然是O(n)
// 因此定义矩阵乘法，然后递归快速幂

/******* 计算快速幂的技巧 ********/
/* 想了一晚上，最后还是要看官方题解，虽然官方题解最后的返回值不对，，
 * 计算快速幂且不用递归的方法是，将整数n转化成 n = 2^a + 2^b +...+2^x;的形式，其中x>...>b>a;
 * 使用temp保留 M^(2^a + 2^b + ...), 不断更新M保留M^(2^a)、M^(2^b)...M(2^x)，最后计算temp = temp * M(2^x)即可。
*/

// 解题思路3是斐波那契数列的通项公式

// 假设M1, M2都是2x2的矩阵
int **matrix_multiple(int **M1, int **M2)
{
    int **M_res = (int **)malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++)
    {
        M_res[i] = (int *)malloc(sizeof(int) * 2);
        for (int j = 0; j < 2; j++)
        {
            // i行乘以j列
            M_res[i][j] = M1[i][0] * M2[0][j] + M1[i][1] * M2[1][j];
        }
    }

    return M_res;
}

// 假设M是2x2矩阵
int **fast_pow(int **M, int n)
{
    int **temp= (int **)malloc(sizeof(int *) * 2);;
    temp[0] = (int *)malloc(sizeof(int) * 2);
    temp[1] = (int *)malloc(sizeof(int) * 2);
    temp[0][0] = 1;
    temp[0][1] = 0;
    temp[1][0] = 0;
    temp[1][1] = 1;

    while (n > 0)
    {
        if ((n & 1) == 1)
        {
            temp = matrix_multiple(temp, M);
        }
        n >>= 1;
        if (n != 0)
            M = matrix_multiple(M, M);
    }

    return temp;
}

int climbStairs(int n)
{
    // 题目已假设n >0
    int **M = (int **)malloc(sizeof(int *) * 2);
    M[0] = (int *)malloc(sizeof(int) * 2);
    M[1] = (int *)malloc(sizeof(int) * 2);
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 1;
    M[1][1] = 0;

    int **M_ret = (int **)malloc(sizeof(int *) * 2);
    M_ret[0] = (int *)malloc(sizeof(int) * 2);
    M_ret[1] = (int *)malloc(sizeof(int) * 2);

    // 因为初始向量为{1,1}
    // 所以直接返回n次幂后的M[1][0]即可
    M_ret = fast_pow(M, n);

    return M_ret[1][0] + M_ret[1][1];
}