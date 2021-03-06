// 根据题解略微修改的代码
// 使用优先队列min堆实现
// 按照题解重新手打一边的答案
// wo shi sha b

/*
#include <mem.h>
#include <stdlib.h>
#include <stdio.h>
*/

// MAX_NUM 必须大于111否则提交时buffer overflow
#define MAX_NUM 110

// 堆中节点结构，包含坐标值及高度
typedef struct {
    int x;
    int y;
    int value;
} Node;

// min堆结构，包含当前容量，最大容量及节点数组
typedef struct{
    int size;
    int maxsize;
    Node *nodes;
} MinHeap;

bool nodes_visited[MAX_NUM * MAX_NUM] = {false};
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

/*
void init_minheap(MinHeap *heap, int maxsize);
void free_heap(MinHeap *heap);
void percolate_up(MinHeap *heap, int pos);
void percolate_dowm(MinHeap *heap, int pos);
int get_size(MinHeap *heap);
void insert_node(MinHeap *heap, Node *node);
Node pop_min(MinHeap *heap);
int trapRainWater(int **heightMap, int heightMapSize, int *heightMapColSize);
*/

/*
int main()
{
    int number_of_rain;
    int height_map[3][6] = {{3,3,4,4,4,2}, {3,1,3,2,1,4}, {7,3,1,6,4,1}};
    int *p[3];
    for (int i = 0; i < 3; i++)
    {
        p[i] = height_map[i];
    }
    int heightcolsize[1] = {6};
    number_of_rain = trapRainWater(p, 3, heightcolsize);

    printf("\nrains:%d", number_of_rain);

    return 0;
}
*/

// min堆初始化
void init_minheap(MinHeap *heap, int maxsize)
{
    heap->size = 0;
    heap->maxsize = maxsize;
    heap->nodes = (Node *)malloc(sizeof(Node) * maxsize);
}

// 清空堆
void free_heap(MinHeap *heap)
{
    heap->size = 0;
    heap->maxsize = 0;
    if (heap->nodes != NULL)
    {
        free(heap->nodes);
    }
}

// 上滤
void percolate_up(MinHeap *heap, int pos)
{
    int father;
    int current_position = pos;
    Node temp = heap->nodes[current_position];

    while(current_position > 0)
    {
        father = (current_position - 1) / 2;
        // 比较节点与其父节点的大小关系
        if ((heap->nodes[father]).value > temp.value)
        {
            heap->nodes[current_position] = heap->nodes[father];
            current_position = father;
        }
        else
        {
            break;
        }
    }
    heap->nodes[current_position] = temp;
}

// 下滤
void percolate_dowm(MinHeap *heap, int pos)
{
    int child;
    int current_position = pos;
    Node temp = heap->nodes[current_position];

    while(current_position < heap->size)
    {
        child = current_position * 2 + 1;
        if (child >= heap->size)
        {
            break;
        }
        // 比较左右儿子大小
        if (child < heap->size - 1 && heap->nodes[child].value > heap->nodes[child + 1].value)
        {
            child++;
        }
        // 比较儿子和父亲大小，若儿子小则交换
        if (heap->nodes[child].value < temp.value)
        {
            heap->nodes[current_position] = heap->nodes[child];
            current_position = child;
        }
        else
        {
            break;
        }
    }
    heap->nodes[current_position] = temp;
}

// 返回堆当前容量
int get_size(MinHeap *heap)
{
    return heap->size;
}

// 插入节点
void insert_node(MinHeap *heap, Node *node)
{
    if (heap->size >= heap->maxsize)
    {
        printf("out of size!\n");
        return;
    }
    heap->nodes[heap->size] = *node;
    heap->size++;
    percolate_up(heap, heap->size - 1);
}

// 弹出最小值
Node pop_min(MinHeap *heap)
{
    Node min_node = heap->nodes[0];
    heap->size--;
    if (heap->size > 0)
    {
        heap->nodes[0] = heap->nodes[heap->size];
        percolate_dowm(heap, 0);
    }
    return min_node;
}

// 接雨水 heightMapSize为行数，数组heightMapColSize为每一行列数的数组
int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize)
{
    int i;
    int result = 0;
    Node new_node;
    Node nextNode;
    MinHeap heap;

    if (heightMapSize <= 0) 
    {
        return 0;
    }

    init_minheap(&heap, MAX_NUM * MAX_NUM);
    (void)memset(nodes_visited, 0, sizeof(bool) * heightMapSize * heightMapColSize[0]);
    for (i = 0; i < heightMapSize; i++) 
    {
        new_node.x = 0;
        new_node.y = i;
        new_node.value = heightMap[i][0];
        insert_node(&heap, &new_node);
        new_node.x = heightMapColSize[0] - 1;
        new_node.y = i;
        new_node.value = heightMap[i][heightMapColSize[0] - 1];
        insert_node(&heap, &new_node);
        nodes_visited[i * heightMapColSize[0]] = true;
        nodes_visited[i * heightMapColSize[0] + heightMapColSize[0] - 1] = true;
    }
    for (i = 1; i < heightMapColSize[0] - 1; i++)
    {
        new_node.x = i;
        new_node.y = 0;
        new_node.value = heightMap[0][i];
        insert_node(&heap, &new_node);
        new_node.x = i;
        new_node.y = heightMapSize - 1;
        new_node.value = heightMap[heightMapSize - 1][i];
        insert_node(&heap, &new_node);
        nodes_visited[i] = true;
        nodes_visited[(heightMapSize - 1) * heightMapColSize[0] + i] = true;
    }

/*
    for (i = 0; i < heap.size; i++)
    {
        printf("%d\t", heap.nodes[i].value);
    }
*/

    while (heap.size > 0)
    {
        new_node = pop_min(&heap);

/*
        printf("\nmin:%d\n", new_node.value);
*/

        for (i = 0; i < 4; i++)
        {
            nextNode.x = new_node.x + direction[i][0];
            nextNode.y = new_node.y + direction[i][1];
            // 超出范围
            if (nextNode.x < 0 || nextNode.x >= heightMapColSize[0] || nextNode.y < 0 || nextNode.y >= heightMapSize)
            {
                continue;
            }
            // 已访问
            if (nodes_visited[nextNode.y * heightMapColSize[0] + nextNode.x])
            {
                continue;
            }
            // 未访问
            nodes_visited[nextNode.y * heightMapColSize[0] + nextNode.x] = true;
            nextNode.value = heightMap[nextNode.y][nextNode.x];
            // 如果下一节点的高度小于该节点的高度，则接水量为二者差值，并将下一节点的高度增加到与当前节点一致
            if (nextNode.value < new_node.value)
            {
                result += new_node.value - nextNode.value;
                nextNode.value = new_node.value;
            }
            insert_node(&heap, &nextNode);

/*
            printf("\nresult:%d\n", result);
            
            for (i = 0; i < heap.size; i++)
            {
                printf("%d\t", heap.nodes[i].value);
            }
*/
        }
    }

    free_heap(&heap);

    return result;
}