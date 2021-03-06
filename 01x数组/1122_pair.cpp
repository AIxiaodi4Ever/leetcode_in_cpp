class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_map<int, int> idxs;
        int m = arr2.size();
        for (int i = 0; i < m; ++i)
            idxs[arr2[i]] = i;
        auto mycmp = [&](int x) -> pair<int, int> {
            return idxs.count(x) ? pair{0, idxs[x]} : pair{1, x};
        };
        sort(arr1.begin(), arr1.end(), [&](int x, int y) -> bool{
            return mycmp(x) < mycmp(y);
        });
        return arr1;
    }
};