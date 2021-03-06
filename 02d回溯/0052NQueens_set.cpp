class Solution {
public:
    int totalNQueens(int n) 
    {
        unordered_set<int> columns, diagonal1, diagonal2;
        return backtrack(n, 0, columns, diagonal1, diagonal2);
    }

    // ÒıÓÃ´«µİ
    int backtrack(int n, int row, unordered_set<int>& col, unordered_set<int>& diag1, unordered_set<int>& diag2)
    {
        if (row == n)
            return 1;
        else
        {
            int count = 0;
            for (int i = 0; i < n; ++i)
            {
                if (col.find(i) != col.end())
                    continue;
                int k_one = row - i;
                if (diag1.find(k_one) != diag1.end())
                    continue;
                int k_two = row + i;
                if (diag2.find(k_two) != diag2.end())
                    continue;

                col.insert(i);
                diag1.insert(k_one);
                diag2.insert(k_two);
                count += backtrack(n, row + 1, col, diag1, diag2);

                col.erase(i);
                diag1.erase(k_one);
                diag2.erase(k_two);
            }
            return count;
        }
    }
};