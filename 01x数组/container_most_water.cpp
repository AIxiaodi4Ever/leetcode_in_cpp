/*��Ŀ����:
    Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n 
vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

����
Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/

/* ����˼·��������⣬�Ƚϼ򵥣�˫ָ�����ͷ������ֻ���м��ֵ���������ߵ�λ��ʱ���ӵ�ˮ�����п������� */
/* ���ÿ�μ������ʱ����ָ���С�߶ȵ�ָ�����м��ƶ�һλ���ٴμ���������������֮ǰ��¼��maxֵ������� */

int maxArea(int* height, int heightSize)
{
    int vomlumn = 0;
    int maxVolumn = 0;
    int left = 0, right = heightSize - 1;

    while (left < right)
    {
        // ���С
        if (height[left] < height[right])
        {
            vomlumn = height[left] * (right - left);
            left++;
        }
        // �ұ�С
        else if(height[left] > height[right])
        {
            vomlumn = height[right] * (right - left);
            right--;
        }
        // ���
        else
        {
            vomlumn = height[left] * (right - left);
            left++;
            right--;
        }

        if (maxVolumn < vomlumn)
        {
            maxVolumn = vomlumn;
        }
    }

    return maxVolumn;
}