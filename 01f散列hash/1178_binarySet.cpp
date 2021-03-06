class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) 
    {
        // 建立word不重复字母集合对应的hash
        unordered_map<int,int> frequency;
        for (const string& word : words)
        {
            int mask = 0;
            for (char ch : word)
                mask |= 1 << (ch - 'a');
            if (__builtin_popcount(mask) <= 7)
                ++frequency[mask];
        }

        vector<int> ans;
        for (const string& puzzle : puzzles)
        {
            int total = 0;

            // 枚举二进制子集方法一
            /*for (int choose = 0; choose < (1 << 6); ++choose)
            {
                int mask = 0;
                for (int i = 0; i < 6; ++i)
                {
                    if (choose & (1 << i))
                        mask |= 1 << (puzzle[i + 1] - 'a');
                }
                mask |= 1 << (puzzle[0] - 'a');
                total += frequency[mask];
            }
            ans.push_back(total);*/

            // 枚举二进制子集方法二
            int mask = 0;
            for (int i = 1; i < 7; ++i)
                mask |= 1 << (puzzle[i] - 'a');
            int subset = mask;
            do {    // do-while循环当subset == 0时是只考虑首字母的情况，因此不用while循环
                int s = subset | 1 << (puzzle[0] - 'a');
                if (frequency.count(s))
                    total += frequency[s];           
                subset = (subset - 1) & mask;
            } while(subset != mask);

            ans.push_back(total);
        }
        return ans;
    }
};