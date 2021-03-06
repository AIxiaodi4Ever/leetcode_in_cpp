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


// 解题思路：寻找前缀节点
/*
1. 观察到对于每一个节点都是先处理根，然后是左子树，最后处理右子树，并且左子树中最后处理的节点，
是左子树中最右的节点（不是下右），该节点为前驱节点。
2. 因此，可以令前驱节点右儿子为当前节点的右儿子，并令当前节点的左儿子为当前节点的右儿子，然后令
左儿子为NULL，之后继续判断下一个节点（即当前节点的右儿子（也即之前的左儿子。。））有没有左子树，
如果有重复之前步骤，否则继续下个节点。直到遇到nullptr。
*/

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if (root == nullptr)
            return;

        TreeNode *curr = root;
        // 这个curr != nullptr，，没想到，之前用的curr->right != nullptr;
        while (curr != nullptr)
        {
            if (curr->left != nullptr)
            {
                TreeNode *preNode = curr->left;
                while (preNode->right != nullptr)
                    preNode = preNode->right;
                preNode->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
