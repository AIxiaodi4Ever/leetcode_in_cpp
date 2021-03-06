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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/course-schedule
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*
1. ˼·��Ϊ���������������󷨣�����Ҫ�ݹ飬����ʹ�ýڵ����ȣ�������һ��ʼ�����ڽӾ����ͬʱû����һ���ڵ㣬����Ҫ���ýڵ�����+1.
2. ʹ�ö��б����������Ϊ0�Ľڵ㣬ÿ�γ���ʱ����ýڵ��ڽӵĽڵ����-1��������Ϊ0�������У���󵱶���Ϊ��ʱ��
����Է��ʵĽڵ��������ܽڵ������򷵻�true����Ϊ��Ȧͼ��һ�������������ڵ����Ȳ�Ϊ0.
3. ����һ��ʼ�������нڵ�Ѱ�����Ϊ0�Ľڵ����У������Ϳ��Ա��ⲻ��ͨͼ�����нڵ�û���ʵ��������

ע�⣺��preRequisties��ÿ�����У�ǰ���Ǳ�ָ��Ľڵ㣬���Ӧ����ǰ�ߵ�indegree+1.
*/

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indegree;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // resizeĬ�ϲ�0
        edges.resize(numCourses);
        indegree.resize(numCourses);

        for (const vector<int>& edge : prerequisites)
        {
            edges[edge[1]].push_back(edge[0]);
            // ǰ���Ǳ�ָ��ģ�������ǰ�ߵ�indegree++
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