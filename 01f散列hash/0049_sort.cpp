class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> dictionary;
        for (const string & s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            dictionary[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};