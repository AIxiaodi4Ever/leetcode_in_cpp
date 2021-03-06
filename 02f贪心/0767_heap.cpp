class Solution {
public:
    string reorganizeString(string S) 
    {
        if (S.size() < 2)
            return S;
        vector<int> counts(26, 0);
        int maxCount = 0;
        for (const char &c : S)
            ++counts[c - 'a'];
        maxCount = *max_element(counts.begin(), counts.end());
        if (maxCount > (S.size() + 1) / 2)
            return "";

        auto cmp = [&](const char& letter1, const char& letter2)->bool {
            return counts[letter1 - 'a'] < counts[letter2 - 'a'];
        };

        priority_queue<char, vector<char>, decltype(cmp)> letterHeap{cmp};
        for (char c = 'a'; c <= 'z'; ++c)
        {
            // c - 'a' not c
            if (counts[c - 'a'] > 0)
                letterHeap.push(c);
        }
        
        string sb = "";
        while (letterHeap.size() > 1)
        {
            char letter1 = letterHeap.top(); letterHeap.pop();
            char letter2 = letterHeap.top(); letterHeap.pop();
            sb += letter1;
            sb += letter2;
            int index1 = letter1 - 'a', index2 = letter2 - 'a';
            --counts[index1];
            --counts[index2];
            if (counts[index1] > 0)
                letterHeap.push(letter1);
            if (counts[index2] > 0)
                letterHeap.push(letter2);
        }
        if (letterHeap.size() > 0)
            sb += letterHeap.top();
        return sb;
    }
};