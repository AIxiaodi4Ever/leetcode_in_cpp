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
// 随机从任意一个点开始，将该点染成红色，执行DFS将临近的点染成绿色；
// 如果遇到一个已经染色的点并且该点与应该染的颜色不同，则返回false；
// 如果整个dfs执行完成，则返回true，注意图不一定连通，所以必须保证所有点都遍历到。

bool my_dfs(int *color, int node, int **graph, int *graphColSize)
{
    // 根据当前节点的颜色计算邻接节点应该具有的颜色
    int nextc = 1 + (color[node] % 2);
    // 遍历邻接表进行dfs
    for (int j = 0; j < graphColSize[node]; j++)
    {
        int neighbor = graph[node][j];
        if (color[neighbor] == 0)
        {
            color[neighbor] = nextc;
            if (!my_dfs(color, neighbor, graph, graphColSize))
                return false;
        }
        else if (color[neighbor] != nextc)
            return false;
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
    int *color = (int *)malloc(sizeof(int) * graphSize);
    // 。。。这里必须sizeof(int) * graphSize否则graph为空时出错
    memset(color, 0, sizeof(int) * graphSize);
    for (int i = 0; i < graphSize; ++i)
    {
        if (color[i] == 0)
        {
            // 没有染色则首先染成红色，1
            color[i] = 1;
            if (!my_dfs(color, i, graph, graphColSize))
            {
                free(color);
                return false;
            }           
        }
    }
    free(color);
    return true;
}                                                                             