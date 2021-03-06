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


// ����˼·��Ѱ��ǰ׺�ڵ�
/*
1. �۲쵽����ÿһ���ڵ㶼���ȴ������Ȼ������������������������������������������Ľڵ㣬
�������������ҵĽڵ㣨�������ң����ýڵ�Ϊǰ���ڵ㡣
2. ��ˣ�������ǰ���ڵ��Ҷ���Ϊ��ǰ�ڵ���Ҷ��ӣ����ǰ�ڵ�������Ϊ��ǰ�ڵ���Ҷ��ӣ�Ȼ����
�����ΪNULL��֮������ж���һ���ڵ㣨����ǰ�ڵ���Ҷ��ӣ�Ҳ��֮ǰ������ӡ���������û����������
������ظ�֮ǰ���裬��������¸��ڵ㡣ֱ������nullptr��
*/

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if (root == nullptr)
            return;

        TreeNode *curr = root;
        // ���curr != nullptr����û�뵽��֮ǰ�õ�curr->right != nullptr;
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
