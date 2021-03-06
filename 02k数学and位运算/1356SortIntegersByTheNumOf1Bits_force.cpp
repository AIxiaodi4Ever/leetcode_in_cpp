class Solution {
public:
    int getBit(int x)
    {
        int res = 0;
        while (x)
        {
            res += x % 2;
            x >>= 1;
        }
        return res;
    }

    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<int> bit(10001, 0);
        for (const int& num : arr)
            bit[num] = getBit(num);
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