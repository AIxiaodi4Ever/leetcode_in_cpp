/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// �����˶�̫�в��ˡ���
// BSF�����������������У���󷵻صľ������һ�������ߡ�
// զ��û�뵽����������������᷵�����һ�����ұ���

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*> nodes;
        int bottomLeft;
        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode *curr = nodes.front();
            nodes.pop();
            bottomLeft = curr->val;
            if (curr->right != nullptr)
                nodes.push(curr->right);
            if (curr->left != nullptr)
                nodes.push(curr->left);
        }
        return bottomLeft;
    }
};