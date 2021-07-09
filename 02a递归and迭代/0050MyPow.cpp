// leetcode:50
// 幂运算
//  -2^31 < n < 2^31 - 1
//  -100.0 < x < 100.0
// 考虑n取最小的特殊情况
#define MIN -2147483648

double myPowPositive(double x, int n)
{
    if (n == 1)
        return x;
    else
    {
        if (n % 2 == 0)
            return myPowPositive(x*x, n/2);
        else
            return x * myPowPositive(x*x, n/2);
    }
}

double myPow(double x, int n)
{

    if (n < 0)
    {
        // n最小就先乘一次
        if (n == MIN)
            return 1/x * myPow(x, n + 1);
        else
        {
            n = -n;
            x = 1/x;
        }
    }


    else if (n == 0 || x == 1)
        return 1;

    return myPowPositive(x, n);
}