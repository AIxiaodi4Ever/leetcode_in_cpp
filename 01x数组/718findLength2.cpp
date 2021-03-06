// leetcode:718
// ����������������
// �����ⷨ���������������£�����O(N^3)���㷨������Ԫ�ض���ͬ���������鵼��������
// ���������ֵ�ԭ���ǣ���ͬԪ��û�ж��룬��˿���ͨ���ƶ���������λ�ã�ʹ��ͬԪ�طֱ���룻
// ������������ͬ�����У�������һ�λ�ʹ���Ƕ��䣻
// ���뷽ʽ�����֣�1.�̶�A�ƶ�B��2.�̶�B�ƶ�A�������ʱ�临�Ӷ�ΪO((M+N)*min(M,N))�ȶ�̬�滮����һ��������
// ���ǣ��ռ临�Ӷ�ΪO(1),ԶԶС�ڶ�̬�滮��O(M*N);

#define max(a,b) ((a > b) ? a : b)
#define min(a,b) ((a < b) ? a : b)

// ÿ��A��B�ƶ�һ���󣬼����ʱ��ͬλ���ϵ������ͬ������
int maxLength(int *A, int *B, int indexA, int indexB, int len)
{
    int ret = 0, k = 0;
    for (int i = 0; i < len; i++)
    {
        if (A[indexA + i] == B[indexB + i])
        {
            k++;
        }
        else
        {
            k = 0;
        }
        ret = max(ret, k);
    }
    return ret;
}

int findLength(int* A, int ASize, int* B, int BSize)
{
    int ans = 0, len = 0;
    // �̶�A������ƶ�B
    for (int i = 0; i < ASize; i++)
    {
        len = min(ASize - i, BSize);
        // ������������������ҵ������ans
        if (ans >= len)
            break;
        int ret = maxLength(A, B, i, 0, len);
        ans = max(ans, ret);
    }

    // �̶�B������ƶ�A��ѭ�����Ʊ�����j��ʾ����
    for (int j = 0; j < BSize; j++)
    {
        len = min(ASize, BSize - j);
        // ������������������ҵ������ans
        if (ans >= len)
            break;
        int ret = maxLength(A, B, 0, j, len);
        ans = max(ans, ret);
    }

    return ans;
}
