class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char, int> freq;
        for (const char &c : tasks)
            ++freq[c];
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto&v)->bool{
            return u.second < v.second;
        })->second;
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u){
            return acc + (u.second == maxExec);
        });

        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
};