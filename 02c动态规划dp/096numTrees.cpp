// leetcode:096
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路：动态规划
// 1.G(n)表示序列n可以组成的二叉查找树个数，F(i,n)表示以i为根，可以组成的序列n的二叉查找树个数；
// 其中 1 <= i <= n; 则G(n) = F(1,n) + ... + F(n,n);边界条件为G(0) = 1, G(1) = 1;
// 而F(i,n) = G(i-1) * G(n-i); <--!注意是乘-->
// 结合以上两式，可以从小到大求G(n)

int numTrees(int n)
{
    int G[n + 1];
    memset(G, 0, sizeof(G));
    G[0] = G[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        // 取1到i分别做根
        for (int j = 1; j <= i; j++)
        {
            // 是笛卡尔积，而不是和
            // 总的数量等于不同左子树的数量乘以右子树的数量
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
}

// 解法2：数学
// 上面推导出来的公式是卡塔兰数C(n)，C(0) = 1， C(n+1) = (2(2n+1)/(n+2)) * c(n);
int numTrees(int n)
{
    long long C = 1;
    for (int i = 0; i < n; i++)
    {
        // *=会出错
        //C *= 2 * (2 * i + 1) / (i + 2);
        C = C * 2 * (2 * i + 1) / (i + 2);
    }
    return (int)C;
}