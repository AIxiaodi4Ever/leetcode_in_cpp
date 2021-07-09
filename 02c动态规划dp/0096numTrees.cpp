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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/unique-binary-search-trees
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// ����˼·����̬�滮
// 1.G(n)��ʾ����n������ɵĶ��������������F(i,n)��ʾ��iΪ����������ɵ�����n�Ķ��������������
// ���� 1 <= i <= n; ��G(n) = F(1,n) + ... + F(n,n);�߽�����ΪG(0) = 1, G(1) = 1;
// ��F(i,n) = G(i-1) * G(n-i); <--!ע���ǳ�-->
// ���������ʽ�����Դ�С������G(n)

int numTrees(int n)
{
    int G[n + 1];
    memset(G, 0, sizeof(G));
    G[0] = G[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        // ȡ1��i�ֱ�����
        for (int j = 1; j <= i; j++)
        {
            // �ǵѿ������������Ǻ�
            // �ܵ��������ڲ�ͬ����������������������������
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
}

// �ⷨ2����ѧ
// �����Ƶ������Ĺ�ʽ�ǿ�������C(n)��C(0) = 1�� C(n+1) = (2(2n+1)/(n+2)) * c(n);
int numTrees(int n)
{
    long long C = 1;
    for (int i = 0; i < n; i++)
    {
        // *=�����
        //C *= 2 * (2 * i + 1) / (i + 2);
        C = C * 2 * (2 * i + 1) / (i + 2);
    }
    return (int)C;
}