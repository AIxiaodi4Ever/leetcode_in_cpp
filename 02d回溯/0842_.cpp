class Solution {
public:
    vector<int> splitIntoFibonacci(string S) 
    {
        vector<int> list;
        backtrack(list, S, S.length(), 0, 0, 0);
        return list;
    }

    // sum use long long
    bool backtrack(vector<int>& list, string &S, int length, int index, long long sum, int prev)
    {
        if (index == length)
            return list.size() >= 3;
        // curr use long long in case some number bigger than INT_MAX
        long long curr = 0;
        for (int i = index; i < length; ++i)
        {
            if (i > index && S[index] == '0')
                break;
            curr = curr * 10 + S[i] - '0';
            if (curr > INT_MAX)
                return false;
            if (list.size() >= 2)
            {
                if (curr < sum)
                    continue;
                else if (curr > sum)
                    break;
            }
            list.push_back(curr);
            // if the deepest function return true the true will return true until the first call
            if (backtrack(list, S, length, i + 1, prev + curr, curr))
            {
                return true;
            }
            list.pop_back();
        }
        return false;
    }
};