class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> arr(n + 1, 0);
        arr[0] = first;
        for (int i = 1; i <= n; ++i) {
            arr[i] = encoded[i - 1] ^ arr[i - 1];
        }
        return arr;
    }
};