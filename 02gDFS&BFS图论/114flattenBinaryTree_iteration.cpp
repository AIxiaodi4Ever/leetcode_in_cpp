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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
�ֶ�����ʵ���������ͬʱչ��
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