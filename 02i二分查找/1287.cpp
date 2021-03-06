class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int span = n / 4 + 1;
        for (int i = 0; i < n; i += span)
        {
            auto iter_left = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto iter_right = upper_bound(arr.begin(), arr.end(), arr[i]);
            if (iter_right - iter_left >= span)
                return arr[i];
        }
        return -1;
    }
};