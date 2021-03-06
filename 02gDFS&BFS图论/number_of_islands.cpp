/*������˼·��

** ��˼·ΪDFS **

**��Ŀ�滻��**
������ӵ��һ��ֻ�������������߻����ˣ���һ��������������ӣ�1���ĵ�ͼ��x������?Ϊ����y��?Ϊ������
����Ҫ�������λ����˵�λ�ý�����ȫ���Ƶ���0����

����˼·��
���ȣ��ҵ����ӵ�λ�ã�x,y�����жϳ����Ƿ������ӡ�
��Σ����ҵ�������λ�ô���x,y�����������û����ˣ��û����˴����������ĸ�ά�Ⱦ����ܵ��Ƶ��������ӡ�
����ظ������������Ƶ���ͼ�ϵ��������ӡ�

���ߣ�every-10
���ӣ�https://leetcode-cn.com/problems/number-of-islands/solution/ji-jian-si-lu-xie-dai-ma-gu-shi-ji-qi-ren-tui-by-e/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/

/* ����ͼ��ʱ�������ӣ�grid[y][x] == '1'�������У����ҵ����ӣ��������ӵ�λ�� */
bool check(char** grid, int gridSize, int* gridColSize, int* xRet, int* yRet) {
    for (int y = 0; y < gridSize; y++) {
        for (int x = 0; x < gridColSize[y]; x++) {
            if (grid[y][x] == '1') {
                *yRet = y;
                *xRet = x;
                return true;
            }
        }
    }
    return false;
}

/* �����������ĸ�ά�Ⱦ����ܵ��Ƶ��������� */
void clearFlag(char** grid, int gridSize, int* gridColSize, int x, int y) {
    if (grid[y][x] == '0') { // �˴���������Ѿ��Ƶ��������κβ���
        return;
    }       
    grid[y][x] = '0'; // �Ƶ�����
    if (y - 1 >= 0) {
        clearFlag(grid, gridSize, gridColSize, x, y - 1); // �����Ƶ���һ��
    }
    if (x - 1 >= 0) {
        clearFlag(grid, gridSize, gridColSize, x - 1, y); // �����Ƶ���һ��
    }
    if (y + 1 < gridSize) {
        clearFlag(grid, gridSize, gridColSize, x, y + 1); // �����Ƶ���һ��
    }
    if (x + 1 < gridColSize[y]) {
        clearFlag(grid, gridSize, gridColSize, x + 1, y); // �����Ƶ���һ��
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    int x, y;
    while (check(grid, gridSize, gridColSize, &x, &y)) {
        clearFlag(grid, gridSize, gridColSize, x, y);
        ans++;
    }
    return ans;
}