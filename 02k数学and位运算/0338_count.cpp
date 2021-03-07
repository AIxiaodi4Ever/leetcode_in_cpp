// dp Œª‘ÀÀ„
class Solution {
public:
    int countOnes(int x)
    {
        int ones = 0;
        while (x)
        {
            x &= (x - 1);
            ++ones;
        }
        return ones;
    }

    vector<int> countBits(int num) 
    {
        vector<int> bits(num + 1);
        for (int i = 0; i <= num; ++i)
        {
            bits[i] = countOnes(i);
        }
        return bits;
    }
};