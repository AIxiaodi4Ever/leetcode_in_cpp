class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.size();
        // 保存目前[left, right]区间内所有元素出现的次数
        vector<int> freqs(26, 0);
        int left = 0, right = 0, maxFreq = 0;
        while (right < n)
        {
            freqs[s[right] - 'A']++;
            maxFreq = max(maxFreq, freqs[s[right] - 'A']);
            // 除非某个元素的频率比当前的maxFreq大，否则不更新maxFreq
            if (right - left + 1 - maxFreq > k)
            {
                freqs[s[left] - 'A']--;
                ++left;
            }
            ++right;
        }
        return right - left;
    }
};