/*该思路为DFS*/
/* 个人觉得这种好一点 */
void wallk(int row, int col, char **grid, int rowMax, int colMax)
{
	int offset[5] = { -1, 0, 1, 0, -1 };

	if (grid[row][col] == '0') {
		return;
	}

        grid[row][col] = '0';

	for (int j = 0; j < 4; j++) {
        if (row + offset[j] >= rowMax || row + offset[j] < 0 || 
            col + offset[j + 1] < 0 || col + offset[j + 1] >= colMax) {
            continue;
        }

           wallk(row + offset[j], col + offset[j + 1], grid, rowMax, colMax);
	}

	return;
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
	int rowMax;
	int colMax;
	int i;
	int j;
	int islandCount = 0;

	if (grid == NULL || gridSize == 0) {
		return 0;
	}

	rowMax = gridSize;
	colMax = gridColSize[0];
	for (i = 0; i < rowMax; i++) {
		for (j = 0; j < colMax; j++) {
			if (grid[i][j] == '0') {
				continue;
			}
			islandCount++;
			wallk(i, j, grid, rowMax, colMax);
		}
	}
	return islandCount;
}

/*
作者：winsin
链接：https://leetcode-cn.com/problems/number-of-islands/solution/c-dfs-ji-yi-bian-li-by-winsin/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/