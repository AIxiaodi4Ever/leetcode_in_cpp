class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int n = arr.size();
        int ret = 1;
        int left = 0, right = 0;
        while (right < n - 1)
        {
            if (left == right)
            {
                if (arr[right] == arr[right + 1])
                    ++left;
                ++right;
            }
            else
            {
                if (arr[right - 1] > arr[right] && arr[right] < arr[right + 1])
                    ++right;
                else if (arr[right - 1] < arr[right] && arr[right] > arr[right + 1])
                    ++right;
                else    
                    left = right;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};