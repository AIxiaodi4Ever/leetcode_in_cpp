// ��ָoffer11

/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת������һ����������������һ����ת��
�����ת�������СԪ�ء����磬���� [3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ1��  

ʾ�� 1��
���룺[3,4,5,1,2]
�����1

ʾ�� 2��
���룺[2,2,2,0,1]
�����0

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int minArray(vector<int>& numbers) 
    {
        int low = 0;
        int high = numbers.size() - 1;
        int pivot = 0;
        while (low < high)
        {
            pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high])
                high = pivot;
            else if(numbers[pivot] > numbers[high])
                low = pivot + 1;
            else
                --high;
        }
        // ��Сֵһ��������low == high��λ��
        return numbers[low];
    }
};