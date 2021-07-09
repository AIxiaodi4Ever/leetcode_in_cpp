// leetcode:785
/*
Given an undirected graph, return true if and only if it is bipartite.
Recall that a graph is bipartite if we can split it's set of nodes into two 
independent subsets A and B such that every edge in the graph has one node in A and another node in B.
The graph is given in the following form: graph[i] is a list of indexes j for which the edge between 
nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges 
or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.

Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.

Note:
    graph will have length in range [1, 100].
    graph[i] will contain integers in range [0, graph.length - 1].
    graph[i] will not contain i or duplicate values.
    The graph is undirected: if any element j is in graph[i], then i will be in graph[j].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-graph-bipartite
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 解题思路：深度优先or广度优先 
// 同样的思路，这里用广度优先，数据结构使用队列；


bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
    int *color = (int *)malloc(sizeof(int) * graphSize);
    memset(color, 0, sizeof(int) * graphSize);

    int *queue = (int *)malloc(sizeof(int) * graphSize);
    for (int i = 0; i < graphSize; i++)
    {
        if (color[i] == 0)
        {
            color[i] = 1;
            int front = 0, rear = 0;
            // 后入前出
            queue[rear++] = i;
            // rear因为自增最后会多1，所以条件是 < 而不是 <=
            while (front < rear)
            {
                // 应该染的颜色为nextc = 1 + (color[queue[front]] % 2);
                int nextc = 1 + (color[queue[front]] % 2);
                // 列数为graphColSize[queue[front]];
                for (int j = 0; j < graphColSize[queue[front]]; j++)
                {
                    // 当前节点为graph[queue[front]][j];
                    int node = graph[queue[front]][j];
                    if (color[node] == 0)
                    {
                        color[node] = nextc;
                        queue[rear++] = node;
                    }
                    else if (color[node] != nextc)
                        return false;
                }
                ++front;
            }
        }
    }
    free(color);
    free(queue);
    return true;
}                                                                             