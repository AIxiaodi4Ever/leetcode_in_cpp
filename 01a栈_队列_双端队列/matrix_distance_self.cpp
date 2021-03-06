/*题目描述: Given a matrix consists of 0 and 1, find the distance of the 
nearest 0 for each cell.The distance between two adjacent cells is 1.
**Note:
1.The number of elements of the given matrix will not exceed 10,000.
2.There are at least one 0 in the given matrix.
3.The cells are adjacent in only four directions: up, down, left and right.
*/
/*#include <stdio.h>
#include <stdlib.h>*/

// 解题思路：使用结构体Node记录矩阵每一个元素的坐标，使用结构体cqueue作为队列。
// 开始先将所有值为0的元素入列，距离为0。之后将所有与这些0邻接的1入列，距离为1，以此类推，直到队列为空。
// 该题解使用输入矩阵记录每一个访问元素的距离，没有浪费多余的内存

// 出现的错误有：dequeue想返回Node，但出现说把int返回给Node的错误，改为dequeue只使front++，取Node在函数外进行。
// judge时，一开始条件写的是if(visited[y][x])，但分配空间时其内部为随机值并未初始化为0，因此应改为if(visited[y][x] == 1).

#define MAX_SIZE 10001

typedef struct{
    int x;
    int y;
} Node;

typedef struct{
    Node data[MAX_SIZE];
    int front;
    int rear;
} cqueue;

int m, n;               // 行和列数
int **visited;          // 记录是否元素访问的矩阵
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    int i, j, k;
    cqueue *nodes = (cqueue *)malloc(sizeof(cqueue));
    Node goal;
    Node temp;

    m = matrixSize;
    n = *matrixColSize;
    int *colsizes = (int *)malloc(sizeof(int) * m);
    visited = (int **)malloc(sizeof(int *) * m);
    for (i = 0; i < m; i++)                             // 初始化访问矩阵，记录每个行矩阵的列数
    {
        visited[i] = (int *)malloc(sizeof(int) * n);
        colsizes[i] = n;
    }

    empty(nodes);                           // 清空队列

    int X[4] = {-1, 0, 1, 0};               // 左上右下
    int Y[4] = {0, 1, 0, -1};

    // 第一次变量记录所有值为0的元素
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                visited[i][j] = 1;          // 标记访问 
                goal.x = j;
                goal.y = i;
                enqueue(nodes, goal);
            }
        }
    }

    while (!isempty(nodes))
    {
        temp = nodes->data[nodes->front+1];
        dequeue(nodes);
        for (k = 0; k < 4; k++)
        {
            goal.x = temp.x + X[k];
            goal.y = temp.y + Y[k];

            if (judge(goal.x, goal.y))
            {
                visited[goal.y][goal.x] = 1;
                matrix[goal.y][goal.x] = matrix[temp.y][temp.x] + 1;    // 距离加1
                enqueue(nodes, goal);                                   // 入列
            }
        }
    }

    *returnSize = m;
    *returnColumnSizes = colsizes;
    return matrix;
}

// 清空队列
void empty(cqueue *nodes)
{
    nodes->rear = nodes->front = -1;
}

// 入列
void enqueue(cqueue *nodes, Node x)
{
    nodes->rear++;
    nodes->data[nodes->rear] = x;
}

// 出列
void dequeue(cqueue *nodes)
{
    nodes->front++;
}

// 判断队列是否为空
int isempty(cqueue *nodes)
{
    if (nodes->front == nodes->rear)
        return 1;
    return 0;
}

// 判断是否越过界限及是否该节点以访问
int judge(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    if (visited[y][x] == 1)
        return 0;
    return 1;
}