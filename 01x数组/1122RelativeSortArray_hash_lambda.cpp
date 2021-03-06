class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_map<int, int> idxs;
        int m = arr2.size();
        for (int i = 0; i < m; ++i)
            idxs[arr2[i]] = i;
        // 引用捕获idxs，不写后置返回也行
        sort(arr1.begin(), arr1.end(), [&](int x, int y) -> bool {
            if (idxs.count(x))
                return idxs.count(y) ? idxs[x] < idxs[y] : true;             
            else
            {
                return idxs.count(y) ? false : x < y;
            }
        });
        return arr1;
    }
};