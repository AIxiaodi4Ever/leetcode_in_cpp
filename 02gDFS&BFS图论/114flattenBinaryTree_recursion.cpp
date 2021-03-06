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


// ����˼·���򵥵ĵݹ�ʵ���������
/*
1. �ݹ�ʱ�Ƚ��������Ľڵ����vector����������
2. ����vector������Ľڵ�չ���ɵ�����
3. ��������ȱ�����޷�ʵ�ֱ�����չ��ͬʱ���У�ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(N)
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