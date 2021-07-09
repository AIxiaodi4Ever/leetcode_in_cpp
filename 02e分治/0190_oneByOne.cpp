class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32 && n > 0; ++i) {
            // 这句话不断把最后一位移到最前面
            ret |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return ret;
    }
};