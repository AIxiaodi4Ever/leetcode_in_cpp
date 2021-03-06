/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true

Example 2:
Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false

Example 3:
Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/same-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr || q == nullptr)
            return false;

        queue<TreeNode *> queue1, queue2;
        queue1.push(p);
        queue2.push(q);
        while (!queue1.empty() && !queue2.empty())
        {
            TreeNode *node1 = queue1.front();
            TreeNode *node2 = queue2.front();
            queue1.pop();
            queue2.pop();
            if (node1->val != node2->val)
                return false;
            if ((node1->left == nullptr) ^ (node2->left == nullptr))
                return false;
            if ((node1->right == nullptr) ^ (node2->right == nullptr))
                return false;
            // 下面条件说明二者都有左儿子
            if (node1->left)
            {
                queue1.push(node1->left);
                queue2.push(node2->left);
            }
            if (node1->right)
            {
                queue1.push(node1->right);
                queue2.push(node2->right);
            }
        }
        return queue1.empty() && queue2.empty();
    }
};