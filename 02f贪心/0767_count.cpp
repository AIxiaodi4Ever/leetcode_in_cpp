class Solution {
public:
    string reorganizeString(string S) 
    {
        if (S.size() < 2)
            return S;
        vector<int> counts(26, 0);
        int length = S.length();
        int maxCount = 0;
        for (int i = 0; i < length; ++i)
        {
            char c = S[i];
            ++counts[c - 'a'];
            maxCount = max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2)
            return "";
        string reorganized(length, ' ');
        int halfLength = length / 2;
        int evenIndex = 0, oddIndex = 1;
        for (int i = 0; i < 26; ++i)
        {
            char c = 'a' + i;
            while (counts[i] > 0 && counts[i] <= halfLength && oddIndex < length)
            {
                reorganized[oddIndex] = c;
                --counts[i];
                oddIndex += 2;
            }
            while (counts[i] > 0)
            {
                reorganized[evenIndex] = c;
                --counts[i];
                evenIndex += 2;
            }
        }
        return reorganized;
    }
};