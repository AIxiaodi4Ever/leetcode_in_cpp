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
思路一：DFS
1. 将图保存成邻接矩阵以后，dfs遍历该图，将最深处的节点最先入栈，这样当回溯到最初的节点时，它所有指向的点都在栈的底部，将该节点入栈。遍历完整个图后，如果栈存在，则自顶向下即位一个拓扑排序。
2. 遍历过程中，一个节点有三种状态，1为未访问，2为正在搜索，3为以入栈，dfs到一个节点的过程中，如果该节点以入栈，则可以回溯，如果该节点未访问，对该节点dfs，只有当该节点为正在搜索时，说明该图存在一个环，不可能有拓扑排序，返回false即可。
3. 还有，因为仅仅需要返回bool值，所以不需要保留实际的栈结构，仅需保存该点的状态即可。
注意：递归的判断条件了不能直接使用visited[vertex] == 1，因为如果这样将valid修改成false，然后返回，只是返回到上层节点，然后接着dfs，并没有直接返回到初始调用点，因此应该以valid作为条件。

*/


class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
public:
    // 0未访问，1正在搜索，2以入栈 
    void myDfs(int i)
    {
        visited[i] = 1;
        for (const int &vertex : edges[i])
        {
            if (visited[vertex] == 0)
            {
                myDfs(vertex);
                if (!valid)
                    return;
            }
            else if (visited[vertex] == 1)
            {
                valid = false;
                return;
            }
        }
        visited[i] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // resize默认补0
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (vector<int>& edge : prerequisites)
        {
            edges[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i)
        {
            if (!visited[i])
                myDfs(i);
        }
        return valid;
    }
};