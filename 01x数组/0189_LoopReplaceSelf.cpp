class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        // ѭ������Ϊ�������Լ��
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start)
        {
            int temp = nums[start];
            int next = start + k;
            while (next % n != start)
            {
                next %= n;
                swap(nums[next], temp);
                next += k;
            }
            swap(nums[start], temp);
        }
    }
};