/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


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


// 解题思路：简单的递归实现先序遍历
/*
1. 递归时先将遍历到的节点存入vector遍历结束后
2. 遍历vector将存入的节点展开成单链表
3. 这样做的缺点是无法实现遍历和展开同时进行，时间复杂度O(N)，空间复杂度O(N)
*/

class Solution {
public:
    void mydfs(TreeNode *root, vector<TreeNode *> &temp)
    {
        if (root != nullptr)
        {
            temp.push_back(root);
            mydfs(root->left, temp);
            mydfs(root->right, temp); 
        }
    }
    void flatten(TreeNode* root) 
    {
        vector<TreeNode *> temp;
        mydfs(root, temp);
        for (int i = 1; i < temp.size(); ++i)
        {
        TreeNode *prev = temp.at(i - 1), *curr = temp.at(i);
        prev->left = nullptr;
        prev->right = curr;
        }
    }
};