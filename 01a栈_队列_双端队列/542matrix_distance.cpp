// leetcode:542
/*��Ŀ����: Given a matrix consists of 0 and 1, find the distance of the 
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
 }node;//�ڵ�ṹ�壬������������
 typedef struct
 {
     node data[10001];
     int rear;
     int front;
 }cqueue;//����
 int isempty(cqueue*a)//�п�
 {
     if(a->rear==a->front)
     {
         return 1;
     }
     return 0;
 }
 void empty(cqueue*a)//���
 {
     a->rear=a->front=-1;
 }
 void push(cqueue*a,node x)//���
 {
     a->rear++;
     a->data[a->rear]=x;
 }
 void pop(cqueue*a)//����
 {
     a->front++;
 }
 cqueue num;
 cqueue*numm=&num;
 node temp;
 node goal;
 int**hash;//����Ƿ���ʹ�
 int m,n;
 int judge(int x,int y)
 {
     if(x<0||x>=m||y<0||y>=n)//�����ǰ���곬���߽�
     {
         return 0;
     }
     if(hash[x][y]==1)//�����ǰ���걻���ʹ�
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
    int Y[4]={-1,0,1,0};//��������
    int*tmp=(int*)malloc(sizeof(int)*m);
    hash=(int**)malloc(sizeof(int*)*m);
    empty(numm);//���г�ʼ��
    for(i=0;i<m;i++)
    {
        hash[i]=(int*)malloc(sizeof(int)*n);
        tmp[i]=n;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]==0)//�����ǰ�ڵ���0�����Ϊ���ʹ�,���
            {
                hash[i][j]=1;
                goal.x=i;
                goal.y=j;
                push(numm,goal);
            }
            else
            {
                hash[i][j]=0;//������Ϊδ���ʹ����ȴ�����
            }
        }
    }

    while(!isempty(numm))//�����л���Ԫ��
    {
        temp=numm->data[numm->front+1];//ȡ����Ԫ��
        pop(numm);
        for(k=0;k<4;k++)
        {
            goal.x=temp.x+X[k];
            goal.y=temp.y+Y[k];//�����������α���
            if(judge(goal.x,goal.y))//�������judge������
            {
                matrix[goal.x][goal.y]=matrix[temp.x][temp.y]+1;//�����ǵ�ǰ�ڵ����+1;
                hash[goal.x][goal.y]=1;//���Ϊ���ʹ�
                push(numm,goal);//���
            }
        }
    }
    *returnSize=m;
    *returnColumnSizes=tmp;
    return matrix;
}
