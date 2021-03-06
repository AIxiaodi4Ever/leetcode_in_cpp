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

/*
手动迭代实现先序遍历同时展开
*/

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if (root == nullptr)
            return;
        stack<TreeNode *> myStack;
        myStack.push(root);
        TreeNode *prev = nullptr;
        while(!myStack.empty())
        {
            TreeNode *curr = myStack.top();
            myStack.pop();
            if (prev != nullptr)
            {
                prev->right = curr;
                prev->left = nullptr;
            }
            TreeNode *left = curr->left, *right = curr->right;
            if (right != nullptr)
                myStack.push(right);
            if (left != nullptr)
                myStack.push(left);
            
            prev = curr;
        }
    }
};