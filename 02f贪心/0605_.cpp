class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        // 1.第一束花前面有i个位置，其中i-1个可以种花，所以可以种i/2束；
        // 2.两束花之间有j-i-1个位置，其中j-i-3个可以种花，所以可以种(j-i-2)/2束；
        // 3.最后一束花后面有m-k-1个位置，其中m-k-2个可以种花，所以可以种(m-k-1)/2束；
        // 4.如果整个花园是空的，那就有m个位置能种花，所以可以种(m+1)/2束。
        int m = flowerbed.size();   // 重定义n导致出错，
        int prev = -1, count = 0;
        for (int i = 0; i < m; ++i)
        {
            if (flowerbed[i] == 1)
            {
                if (prev == -1)
                    count += i / 2;
                else
                    count += (i - prev - 2) / 2;
            
                if (count >= n)
                    return true;
                // 把这句话写在了if外面导致出错，
                prev = i;
            }
        }
        if (prev == -1)
            count += (m + 1) / 2;
        else
            count += (m - prev - 1) / 2;

        return count >= n;
    }
};