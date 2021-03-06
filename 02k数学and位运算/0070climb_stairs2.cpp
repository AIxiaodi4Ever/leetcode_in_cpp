// leetcode:070
// ��̬�滮����������ݻ�ͨ�ʽ

// ѭ����ʱ�临�Ӷ�ΪO(n)������
// ����˼·2�����������
/*
 * [1 1] [ f(n) ]  = [f(n) + f(n-1)]  = [1 1]^n [f(1)] = [f(n+1)]
 * [1 0] [f(n-1)]    [    f(n)     ]    [1 0]   [f(0)]   [ f(n) ]
 * 
*/
// ������2x2�ľ���
// ����ٷ���ⷽ��������Ȥ
// ֱ�Ӽ���n�η���ʱ�临�Ӷ���Ȼ��O(n)
// ��˶������˷���Ȼ��ݹ������

/******* ��������ݵļ��� ********/
/* ����һ���ϣ������Ҫ���ٷ���⣬��Ȼ�ٷ�������ķ���ֵ���ԣ���
 * ����������Ҳ��õݹ�ķ����ǣ�������nת���� n = 2^a + 2^b +...+2^x;����ʽ������x>...>b>a;
 * ʹ��temp���� M^(2^a + 2^b + ...), ���ϸ���M����M^(2^a)��M^(2^b)...M(2^x)��������temp = temp * M(2^x)���ɡ�
*/

// ����˼·3��쳲��������е�ͨ�ʽ

// ����M1, M2����2x2�ľ���
int **matrix_multiple(int **M1, int **M2)
{
    int **M_res = (int **)malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++)
    {
        M_res[i] = (int *)malloc(sizeof(int) * 2);
        for (int j = 0; j < 2; j++)
        {
            // i�г���j��
            M_res[i][j] = M1[i][0] * M2[0][j] + M1[i][1] * M2[1][j];
        }
    }

    return M_res;
}

// ����M��2x2����
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
    // ��Ŀ�Ѽ���n >0
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

    // ��Ϊ��ʼ����Ϊ{1,1}
    // ����ֱ�ӷ���n���ݺ��M[1][0]����
    M_ret = fast_pow(M, n);

    return M_ret[1][0] + M_ret[1][1];
}