/* leetcode:990     难度：一般*/
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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/satisfiability-of-equality-equations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

/* 
解题思路：
    1.使用不相交集，等式左右的节点必定属于同一集合;
    2.先遍历所有等式，构造不相交集，将每一个等式前面字母的根节点的父节点指向后面字母的根节点;
        注：如果父节点是自身，说明该变量为所在的连通分量的根节点，一开始所有节点的父节点都指向自己。
    3。再遍历所有不等式，如果不等式两边字母的根节点相同，则返回false，遍历完所有不等式都不返回false,则返回true。
*/

// 存储字母a...z的父节点
int parent[26];

// my_fin查找节点的根节点
int my_find(int index)
{
    if (parent[index] == index)
        return index;
    else
        return my_find(parent[index]);
}

// my_union将前者根的父节点指向后者的根
void my_union(int index1, int index2)
{
    parent[my_find(index1)] = my_find(index2);
}

bool equationsPossible(char ** equations, int equationsSize)
{
    // 存储临时索引
    int index1, index2; 

    // 每个字母的父节点最初都是本身
    for (int i = 0; i < 26; i++)
    {
        parent[i] = i;
    }

    // 遍历所有等式
    for (int i = 0; i < equationsSize; i++)
    {
        if (equations[i][1] == '=')
        {
            index1 = equations[i][0] - 'a';
            index2 = equations[i][3] - 'a';
            my_union(index1, index2);
        }
    }

    // 遍历所有不等式
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