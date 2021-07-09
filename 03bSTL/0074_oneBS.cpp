class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int midVal = matrix[mid / n][mid % n];
            if (target < midVal) {
                right = mid;
            }
            else if (target > midVal) {
                left = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};