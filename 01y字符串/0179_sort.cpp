class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& x, const int& y)->bool {
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return x * sy + y > y * sx + x;
        });

        if (nums[0] == 0) {
            return "0";
        }

        string ret;
        for (int &num : nums) {
            ret += to_string(num);
        }

        return ret;
    }
};