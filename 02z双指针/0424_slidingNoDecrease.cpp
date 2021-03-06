class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.size();
        // ����Ŀǰ[left, right]����������Ԫ�س��ֵĴ���
        vector<int> freqs(26, 0);
        int left = 0, right = 0, maxFreq = 0;
        while (right < n)
        {
            freqs[s[right] - 'A']++;
            maxFreq = max(maxFreq, freqs[s[right] - 'A']);
            // ����ĳ��Ԫ�ص�Ƶ�ʱȵ�ǰ��maxFreq�󣬷��򲻸���maxFreq
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