/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
 which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

 
Constraints:
    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
    Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.
    1 <= numCourses <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
1. 思路二为正常的拓扑排序求法，不需要递归，而是使用节点的入度，这样在一开始创建邻接矩阵的同时没加入一个节点，就需要将该节点的入度+1.
2. 使用队列保留所有入度为0的节点，每次出列时将与该节点邻接的节点入度-1，如果入度为0，则入列，最后当队列为空时，
如果以访问的节点数等于总节点数，则返回true，因为有圈图，一定至少有两个节点的入度不为0.
3. 还有一开始遍历所有节点寻找入度为0的节点入列，这样就可以避免不连通图可能有节点没访问到的情况。

注意：在preRequisties的每个边中，前者是被指向的节点，因此应该是前者的indegree+1.
*/

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indegree;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // resize默认补0
        edges.resize(numCourses);
        indegree.resize(numCourses);

        for (const vector<int>& edge : prerequisites)
        {
            edges[edge[1]].push_back(edge[0]);
            // 前者是被指向的，所以是前者的indegree++
            ++indegree[edge[0]];
        }

        queue<int> vertexs;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                vertexs.push(i);
        }

        int visited = 0;
        while (!vertexs.empty())
        {
            ++visited;
            int vertex = vertexs.front();
            vertexs.pop();
            for (const int u : edges[vertex])
            {
                --indegree[u];
                if (indegree[u] == 0)
                    vertexs.push(u);
            }
        }

        return visited == numCourses;
    }
};