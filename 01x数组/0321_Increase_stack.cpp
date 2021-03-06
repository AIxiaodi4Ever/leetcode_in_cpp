class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int m = nums1.size(), n = nums2.size();
        int start = max(0, k - n), end = min(m, k);
        vector<int> maxSequence(k, 0);
        for (int i = start; i <= end; ++i)
        {
            vector<int> subSequence1(maxSubsequence(nums1, i));
            vector<int> subSequence2(maxSubsequence(nums2, k - i));
            vector<int> curMaxSq(mergeSequence(subSequence1, subSequence2));
            if (compareSequence(curMaxSq, 0, maxSequence, 0) > 0)
                maxSequence.swap(curMaxSq);
        }
        return maxSequence;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        int length = nums.size();
        int remain = length - k;
        vector<int> stack(k, 0);
        int top = -1;
        for (int i = 0; i < length; ++i)
        {
            // 通过这个while处理序列递增的情况
            while (top >= 0 && nums[i] > stack[top] && remain > 0)
            {
                --top;
                --remain;
            }
            // 这里是k-1不是k，否则越界
            if (top < k - 1)
                stack[++top] = nums[i];
            // 这个else处理已经填满且序列递减的情况
            else
            {
                --remain;
            }
        }
        return stack;
    }

    vector<int> mergeSequence(vector<int>& subs1, vector<int>& subs2)
    {
        int x = subs1.size(), y = subs2.size();
        if (x == 0)
            return subs2;
        if (y == 0)
            return subs1;
        int mergeLength = x + y;
        vector<int> merged(mergeLength);
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergeLength; ++i)
        {
            if (compareSequence(subs1, index1, subs2, index2) > 0)
                merged[i] = subs1[index1++];
            else
                merged[i] = subs2[index2++];
        }
        return merged;
    }

    int compareSequence(vector<int>& subs1, int index1, vector<int>& subs2, int index2)
    {
        int x = subs1.size(), y = subs2.size();
        while (index1 < x && index2 < y)
        {
            int difference = subs1[index1] - subs2[index2];
            if (difference != 0)
                return difference;
            ++index1;
            ++index2;
        }
        return (x - index1) - (y - index2);
    }
};