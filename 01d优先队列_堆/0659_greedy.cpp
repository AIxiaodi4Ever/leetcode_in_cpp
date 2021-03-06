class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;
        for (const int &x : nums)
            ++countMap[x];
        for (const int &x : nums)
        {
            if (countMap[x] > 0)
            {
                if (endMap[x - 1] > 0)
                {
                    --countMap[x];
                    --endMap[x - 1];
                    ++endMap[x];
                }
                else
                {
                    if (countMap[x + 1] > 0 && countMap[x + 2] > 0)
                    {
                        --countMap[x];
                        --countMap[x + 1];
                        --countMap[x + 2];
                        ++endMap[x + 2];
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
};