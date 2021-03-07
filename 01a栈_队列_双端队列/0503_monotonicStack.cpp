// 单调栈 数组
// 因为遍历一趟一定能得到答案，所以栈最后不为空也没事，栈最后一定不为空，栈内存储的是数组中最大值对应的索引
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        for (int i = 0; i < 2 * n - 1; ++i)
        {
            while (!stk.empty() && nums[i % n] > nums[stk.top()])
            {
                ans[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ans;
    }
};