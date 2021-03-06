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
˼·һ��DFS
1. ��ͼ������ڽӾ����Ժ�dfs������ͼ��������Ľڵ�������ջ�����������ݵ�����Ľڵ�ʱ��������ָ��ĵ㶼��ջ�ĵײ������ýڵ���ջ������������ͼ�����ջ���ڣ����Զ����¼�λһ����������
2. ���������У�һ���ڵ�������״̬��1Ϊδ���ʣ�2Ϊ����������3Ϊ����ջ��dfs��һ���ڵ�Ĺ����У�����ýڵ�����ջ������Ի��ݣ�����ýڵ�δ���ʣ��Ըýڵ�dfs��ֻ�е��ýڵ�Ϊ��������ʱ��˵����ͼ����һ���������������������򣬷���false���ɡ�
3. ���У���Ϊ������Ҫ����boolֵ�����Բ���Ҫ����ʵ�ʵ�ջ�ṹ�����豣��õ��״̬���ɡ�
ע�⣺�ݹ���ж������˲���ֱ��ʹ��visited[vertex] == 1����Ϊ���������valid�޸ĳ�false��Ȼ�󷵻أ�ֻ�Ƿ��ص��ϲ�ڵ㣬Ȼ�����dfs����û��ֱ�ӷ��ص���ʼ���õ㣬���Ӧ����valid��Ϊ������

*/


class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
public:
    // 0δ���ʣ�1����������2����ջ 
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
        return valid;
    }
};