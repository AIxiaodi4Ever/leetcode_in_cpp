class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size(), len = 1;
        if (n == 0)
            return 0;
        // d[i]�б�����ǳ���Ϊi��ĩβԪ����С�ĵ��������е�ĩβԪ��
        // ��ʼֵ�Ǽ�����Ҫ����Ϊѭ��ʱֻ����i��iǰ���Ԫ�أ�����ȷ�����Ҳ�����λ��0
        vector<int> d(n + 1, 0);    
        // ���ǳ�ʼ��d[1]���½�����ܴ�1�Ĵ���
        d[len] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            // ���nums[i]����d[len]˵���������еĳ��ȿ�������
            if (nums[i] > d[len])
                d[++len] = nums[i];
            // �����������d��ǰ����ֲ���d�����һ��d[len']С��nums[i]��len'��d[len'+1]����Ϊnums[i]
            // ��Ϊʹ���˶��ֲ��ң�����ԭ����d[len'+1]һ�����ڵ���nums[i]����֤�˳���Ϊlen'+1����������������
            // �����˵�ҵ�d�е�һ��С��nums[i]��d[k]Ӧ���Ǳ��󣬻�����˼�ǵ�����
            else
            {
                // ��1��ʼ
                int left = 1, right = len, pos = 0;
                while (left <= right)
                {
                    int mid = left + ((right - left) >> 1);
                    //int mid = (left + right) >> 1;
                    if (d[mid] < nums[i])
                    {
                        left = mid + 1;
                        pos = mid;  
                    }
                    else
                        right = mid - 1;
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};