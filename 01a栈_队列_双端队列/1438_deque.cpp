class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        deque<int> queMin, queMax;
        int left = 0, right = 0;
        int ans = 0;
        int n = nums.size();
        while (right < n)
        {
            while (!queMax.empty() && queMax.back() < nums[right])
                queMax.pop_back();
            while (!queMin.empty() && queMin.back() > nums[right])
                queMin.pop_back();
            queMax.push_back(nums[right]);
            queMin.push_back(nums[right]);
            while (queMax.front() - queMin.front() > limit) // �ٷ�����һ�����߲�Ϊ�յ��жϣ���ʵ���϶��߲�����Ϊ�գ���Ϊ�����������г���Ϊ1����ֵΪ0����limit��СҲ��0
            {
                if (nums[left] == queMax.front())
                    queMax.pop_front();
                if (nums[left] == queMin.front())
                    queMin.pop_front();
                ++left;
            }
            ++right;
            ans = max(ans, right - left);
        }
        return ans;
    }
};