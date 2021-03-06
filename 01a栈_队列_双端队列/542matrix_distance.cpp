// leetcode:542
/*题目描述: Given a matrix consists of 0 and 1, find the distance of the 
nearest 0 for each cell.The distance between two adjacent cells is 1.
**Note:
1.The number of elements of the given matrix will not exceed 10,000.
2.There are at least one 0 in the given matrix.
3.The cells are adjacent in only four directions: up, down, left and right.
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 typedef struct
 {
     int x;
     int y;
 }node;//节点结构体，包含横纵坐标
 typedef struct
 {
     node data[10001];
     int rear;
     int front;
 }cqueue;//队列
 int isempty(cqueue*a)//判空
 {
     if(a->rear==a->front)
     {
         return 1;
     }
     return 0;
 }
 void empty(cqueue*a)//清空
 {
     a->rear=a->front=-1;
 }
 void push(cqueue*a,node x)//入队
 {
     a->rear++;
     a->data[a->rear]=x;
 }
 void pop(cqueue*a)//出队
 {
     a->front++;
 }
 cqueue num;
 cqueue*numm=&num;
 node temp;
 node goal;
 int**hash;//标记是否访问过
 int m,n;
 int judge(int x,int y)
 {
     if(x<0||x>=m||y<0||y>=n)//如果当前坐标超出边界
     {
         return 0;
     }
     if(hash[x][y]==1)//如果当前坐标被访问过
     {
         return 0;
     }
     return 1;
 }
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    m=matrixSize;
    n=matrixColSize[0];
    int i,j,k;
    int X[4]={0,-1,0,1};
    int Y[4]={-1,0,1,0};//左上右下
    int*tmp=(int*)malloc(sizeof(int)*m);
    hash=(int**)malloc(sizeof(int*)*m);
    empty(numm);//队列初始化
    for(i=0;i<m;i++)
    {
        hash[i]=(int*)malloc(sizeof(int)*n);
        tmp[i]=n;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]==0)//如果当前节点是0，标记为访问过,入队
            {
                hash[i][j]=1;
                goal.x=i;
                goal.y=j;
                push(numm,goal);
            }
            else
            {
                hash[i][j]=0;//否则标记为未访问过，等待访问
            }
        }
    }

    while(!isempty(numm))//当队列还有元素
    {
        temp=numm->data[numm->front+1];//取队首元素
        pop(numm);
        for(k=0;k<4;k++)
        {
            goal.x=temp.x+X[k];
            goal.y=temp.y+Y[k];//左上右下依次遍历
            if(judge(goal.x,goal.y))//如果满足judge的条件
            {
                matrix[goal.x][goal.y]=matrix[temp.x][temp.y]+1;//层数是当前节点层数+1;
                hash[goal.x][goal.y]=1;//标记为访问过
                push(numm,goal);//入队
            }
        }
    }
    *returnSize=m;
    *returnColumnSizes=tmp;
    return matrix;
}
