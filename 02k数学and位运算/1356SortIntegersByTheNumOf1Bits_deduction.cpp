class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<int> bit(10001, 0);
        for (int i = 0; i < 10001; ++i)
        {
            bit[i] = bit[i>>1] + i % 2;
        }
        // 这里lambda捕获的是bit
        sort(arr.begin(), arr.end(), [&](int x, int y) -> bool
            {
                if (bit[x] < bit[y])
                    return true;
                if (bit[x] > bit[y])
                    return false;
                return x < y;
            });
        return arr;
    }
};