/* leetcode:990     �Ѷȣ�һ��*/
/* Given an array equations of strings that represent relationships between variables, 
each string equations[i] has length 4 and takes one of two different forms: "a==b" or 
"a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent
one-letter variable names.
Return true if and only if it is possible to assign integers to variable names so as to
satisfy all the given equations.

Example 1:
Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  
There is no way to assign the variables to satisfy both equations.

Example 2:
Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

Example 3:
Input: ["a==b","b==c","a==c"]
Output: true

Example 4:
Input: ["a==b","b!=c","c==a"]
Output: false

Example 5:
Input: ["c==c","b==d","x!=z"]
Output: true

Note:
    1 <= equations.length <= 500
    equations[i].length == 4
    equations[i][0] and equations[i][3] are lowercase letters
    equations[i][1] is either '=' or '!'
    equations[i][2] is '='

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/satisfiability-of-equality-equations
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� */

/* 
����˼·��
    1.ʹ�ò��ཻ������ʽ���ҵĽڵ�ض�����ͬһ����;
    2.�ȱ������е�ʽ�����첻�ཻ������ÿһ����ʽǰ����ĸ�ĸ��ڵ�ĸ��ڵ�ָ�������ĸ�ĸ��ڵ�;
        ע��������ڵ�������˵���ñ���Ϊ���ڵ���ͨ�����ĸ��ڵ㣬һ��ʼ���нڵ�ĸ��ڵ㶼ָ���Լ���
    3���ٱ������в���ʽ���������ʽ������ĸ�ĸ��ڵ���ͬ���򷵻�false�����������в���ʽ��������false,�򷵻�true��
*/

// �洢��ĸa...z�ĸ��ڵ�
int parent[26];

// my_fin���ҽڵ�ĸ��ڵ�
int my_find(int index)
{
    if (parent[index] == index)
        return index;
    else
        return my_find(parent[index]);
}

// my_union��ǰ�߸��ĸ��ڵ�ָ����ߵĸ�
void my_union(int index1, int index2)
{
    parent[my_find(index1)] = my_find(index2);
}

bool equationsPossible(char ** equations, int equationsSize)
{
    // �洢��ʱ����
    int index1, index2; 

    // ÿ����ĸ�ĸ��ڵ�������Ǳ���
    for (int i = 0; i < 26; i++)
    {
        parent[i] = i;
    }

    // �������е�ʽ
    for (int i = 0; i < equationsSize; i++)
    {
        if (equations[i][1] == '=')
        {
            index1 = equations[i][0] - 'a';
            index2 = equations[i][3] - 'a';
            my_union(index1, index2);
        }
    }

    // �������в���ʽ
    for (int i = 0; i < equationsSize; i++)
    {
        if (equations[i][1] == '!')
        {
            index1 = equations[i][0] - 'a';
            index2 = equations[i][3] - 'a';
            if (my_find(index1) == my_find(index2))
                return false;
        }
    }

    return true;
}