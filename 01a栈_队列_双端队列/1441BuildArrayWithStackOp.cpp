class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        static const std::string pushOp = "Push";
        static const std::string popOp = "Pop";
        
        std::vector<std::string> res;
        int prev = 0;
        for (const int &num : target) {
            for (int i = 0; i < num - prev - 1; ++i) {
                res.push_back(pushOp);
                res.push_back(popOp);
            }
            res.push_back(pushOp);
            prev = num;
        }

        return res;
    }
};