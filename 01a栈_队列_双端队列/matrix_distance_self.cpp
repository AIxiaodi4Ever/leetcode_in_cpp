/*��Ŀ����: Given a matrix consists of 0 and 1, find the distance of the 
nearest 0 for each cell.The distance between two adjacent cells is 1.
**Note:
1.The number of elements of the given matrix will not exceed 10,000.
2.There are at least one 0 in the given matrix.
3.The cells are adjacent in only four directions: up, down, left and right.
*/
/*#include <stdio.h>
#include <stdlib.h>*/

// ����˼·��ʹ�ýṹ��Node��¼����ÿһ��Ԫ�ص����꣬ʹ�ýṹ��cqueue��Ϊ���С�
// ��ʼ�Ƚ�����ֵΪ0��Ԫ�����У�����Ϊ0��֮����������Щ0�ڽӵ�1���У�����Ϊ1���Դ����ƣ�ֱ������Ϊ�ա�
// �����ʹ����������¼ÿһ������Ԫ�صľ��룬û���˷Ѷ�����ڴ�

// ���ֵĴ����У�dequeue�뷵��Node��������˵��int���ظ�Node�Ĵ��󣬸�Ϊdequeueֻʹfront++��ȡNode�ں�������С�
// judgeʱ��һ��ʼ����д����if(visited[y][x])��������ռ�ʱ���ڲ�Ϊ���ֵ��δ��ʼ��Ϊ0�����Ӧ��Ϊif(visited[y][x] == 1).

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

int m, n;               // �к�����
int **visited;          // ��¼�Ƿ�Ԫ�ط��ʵľ���
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
    for (i = 0; i < m; i++)                             // ��ʼ�����ʾ��󣬼�¼ÿ���о��������
    {
        visited[i] = (int *)malloc(sizeof(int) * n);
        colsizes[i] = n;
    }

    empty(nodes);                           // ��ն���

    int X[4] = {-1, 0, 1, 0};               // ��������
    int Y[4] = {0, 1, 0, -1};

    // ��һ�α�����¼����ֵΪ0��Ԫ��
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                visited[i][j] = 1;          // ��Ƿ��� 
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
                matrix[goal.y][goal.x] = matrix[temp.y][temp.x] + 1;    // �����1
                enqueue(nodes, goal);                                   // ����
            }
        }
    }

    *returnSize = m;
    *returnColumnSizes = colsizes;
    return matrix;
}

// ��ն���
void empty(cqueue *nodes)
{
    nodes->rear = nodes->front = -1;
}

// ����
void enqueue(cqueue *nodes, Node x)
{
    nodes->rear++;
    nodes->data[nodes->rear] = x;
}

// ����
void dequeue(cqueue *nodes)
{
    nodes->front++;
}

// �ж϶����Ƿ�Ϊ��
int isempty(cqueue *nodes)
{
    if (nodes->front == nodes->rear)
        return 1;
    return 0;
}

// �ж��Ƿ�Խ�����޼��Ƿ�ýڵ��Է���
int judge(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    if (visited[y][x] == 1)
        return 0;
    return 1;
}