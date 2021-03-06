/*题目描述：Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

example:
    Input: [1,2,3,null,5,null,4]
    Output: [1, 3, 4]
    Explanation:

    1            <---
    /   \
    2     3         <---
    \     \
    5     4       <---
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 第一次没看题解写出来:p
// 解题思路：BSF记录每一层最后遍历的数
// 先使用先序遍历获得返回数组的大小
// 之后用先序遍历实现BSF，使用变量depth标记当前深度，数组right_val记录每一深度最右的数。
// 每次遍历到某一深度的节点时，则用当前节点数值代替数组中同样深度depth的值

// 获得返回数组大小
void get_depth(struct TreeNode *root, int level, int *returnSize)
{
    if (root == NULL)
        return;
    
    else
    {
        // 深度从0开始，returnSize从1开始，因此比较其和depth+1的大小关系
        // 每次计算depth+1使时间达到4ms,改成level从1开始，不用depth+1，时间节省到0ms
        // *returnSize = *returnSize > (depth+1) ? *returnSize : (depth+1);
        *returnSize = *returnSize > level ? *returnSize : level;
        get_depth(root->left, level + 1, returnSize);
        get_depth(root->right, level + 1, returnSize);
    }
}

// 获得最右边的值
void update_value(struct TreeNode *root, int depth, int *right_val)
{
    if (root == NULL)
        return;
    
    else 
    {
        right_val[depth] = root->val;
        update_value(root->left, depth + 1, right_val);
        update_value(root->right, depth + 1, right_val);
    }
}

int *rightSideView(struct TreeNode *root, int *returnSize)
{
    int level = 1;
    int *right_val;

    *returnSize = 0;

    // 获得returnSize的值
    get_depth(root, level, returnSize);

    right_val = (int *)malloc(sizeof(int) * *returnSize);

    update_value(root, 0, right_val);

    return right_val;
}