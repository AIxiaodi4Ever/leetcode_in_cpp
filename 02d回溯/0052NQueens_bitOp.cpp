class Solution {
public:
    int totalNQueens(int n) 
    {
        return solve(n, 0, 0, 0, 0);
    }

    int solve(int n, int row, int col, int diags1, int diags2)
    {
        if (row == n)
            return 1;
        else
        {
            int count = 0;
            int availablePos = ((1 << n) - 1) & (~(col | diags1 | diags2));
            while (availablePos != 0)
            {
                int curPos = availablePos & (-availablePos);
                availablePos &= (availablePos - 1);
                count += solve(n, row + 1, col | curPos, (diags1 | curPos) << 1, (diags2 | curPos) >> 1); 
            }
            return count;
        }
    }
};