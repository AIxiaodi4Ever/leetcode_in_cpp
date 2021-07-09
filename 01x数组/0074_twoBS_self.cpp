class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int leftRow = 0, rightRow = m;
        int possibleRow;
        while (leftRow < rightRow) {
            int midRow = leftRow + (rightRow - leftRow) / 2;
            if (target < matrix[midRow][0]) {
                rightRow = midRow;
            }
            else if (target > matrix[midRow][n - 1]) {
                leftRow = midRow + 1;
            }
            else {
                possibleRow = midRow;
                break;
            }
        }

        if (leftRow >= rightRow) {
            return false;
        }

        int leftCol = 0, rightCol = n;
        while (leftCol < rightCol) {
            int midCol = leftCol + (rightCol - leftCol) / 2;
            if (target < matrix[possibleRow][midCol]) {
                rightCol = midCol;
            }
            else if (target > matrix[possibleRow][midCol]) {
                leftCol = midCol + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};