class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> counter;
        for (const int& n : nums)
        {
            if (counter.count(n))
                return true;
            counter.insert(n);
        }
        return false;
    }
};