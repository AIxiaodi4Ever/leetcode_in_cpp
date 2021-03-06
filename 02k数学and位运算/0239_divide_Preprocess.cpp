class Solution {
public:
    /********************************************************/
    /* �����鰴��k��һ����з��飬���һ���Ԫ����Ŀ����С��k  */
    /* ����ÿһ��ĳһλ�õ�ǰ׺���ֵ�ͺ�׺���ֵ             */
    /* prefixMax[i]��ʾi��Ӧ�ķ�������i��β��ǰ׺�����ֵ     */
    /* suffixMax[i]��ʾi��Ӧ�ķ�������i��ʼ�ĺ�׺�����ֵ     */
    /* ���i��k�ı�����ôi������i��β��ǰ׺��ΨһԪ��         */
    /* ���i+1��k�ı�����ôi������i��ʼ�ĺ�׺��ΨһԪ��       */
    /*******************************************************/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        // ǰ׺ֻ�ܴ�ͷ��ʼ����׺ֻ�ܴ�β����
        int n = nums.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        // ����i��β��ǰ׺���ֵ
        for (int i = 0; i < n; ++i)
        {
            if (i % k == 0)
                prefixMax[i] = nums[i];
            else
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
        // ����i��ʼ�ĺ�׺���ֵ
        for (int i = n - 1; i >= 0; --i)
        {
            if (i == n - 1 || (i + 1) % k == 0)
                suffixMax[i] = nums[i];
            else
                suffixMax[i] = max(suffixMax[i + 1], nums[i]);
        }

        vector<int> ans;
        for (int i = 0; i <= n - k; ++i)
            ans.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
        return ans;
    }
};