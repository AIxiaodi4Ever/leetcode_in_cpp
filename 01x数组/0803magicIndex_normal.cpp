// ������ 08.03
// ԭ�����ŵ�һС�ʵ���˼�Ƕ��ֲ���
// ��ֱ�ӿ�����ʹ�ñ���+��Ծ�Ը���

class Solution {
public:
    int findMagicIndex(vector<int>& nums) 
    {
        int len = nums.size();
        int i = 0;
        while ( i < len )
        {
            if (nums[i] == i)
                return i;
            if (nums[i] > i)
            {
                i = nums[i];
                continue;
            }
            ++i;
        }
        return -1;
    }
};