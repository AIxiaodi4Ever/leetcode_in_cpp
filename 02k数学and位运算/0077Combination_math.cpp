class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> temp;
        vector<vector<int>> ans;

        for (int i = 1; i <= k; ++i)
            temp.push_back(i);
        temp.push_back(n + 1);
        
        int j = 0;
        while (j < k)
        {
            ans.emplace_back(temp.begin(), temp.begin() + k);
            // 寻找第一个temp[j]+1 != temp[j+1]的位置
            // 将0~j-1位置处的数复位(移到最低位)
            // 这步很关键，每次都要把j置0，从头开始找
            j = 0;
            while (j < k && temp[j] + 1 == temp[j + 1])
            {
                temp[j] = j + 1;
                ++j;
            }
            // 此时j是第一个temp[j]+1!=temp[j+1]的位置
            ++temp[j];
        }

        return ans;
    }
};