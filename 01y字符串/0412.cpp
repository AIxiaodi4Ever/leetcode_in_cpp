class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            string curr;
            if (i % 3 == 0) {
                curr += "Fizz";
            }
            if (i % 5 == 0) {
                curr += "Buzz";
            }
            if (curr.size() == 0) {
                curr += to_string(i);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};