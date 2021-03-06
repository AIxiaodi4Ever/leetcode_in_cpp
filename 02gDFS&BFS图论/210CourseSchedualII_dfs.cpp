/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses 
you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to 
finish all courses, return an empty array.

Example 1:
Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .

Example 2:
Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

Note:
    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
    Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/course-schedule-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


/*
����˼·һ��DFS
ͬ��������Ľڵ�����ջ(vectorʵ��)�����תջ�󷵻ؼ��ɡ����validΪfalse����һ���յ�vector<int>��
�������һ���ؼ�������207�к��Եģ����Ǳ����ڽӾ���ʱ����Ҫ���ýڵ��Ƿ���ʹ������δ�����ٽ���dfs������õ���������һ�����ġ���

*/


class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> order;
    bool valid = true;
public:
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
        order.push_back(i);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // resizeĬ�ϲ�0
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
        if (!valid)
            return vector<int> {};
        reverse(order.begin(), order.end());
        return order;
    }
};