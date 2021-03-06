/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        TreeNode* predecessor;
        while (root != nullptr)
        {
            // ����������ֱ��ѹ���
            if (root->left == nullptr)
            {
                ans.push_back(root->val);
                root = root->right;
            }
            else
            {
                predecessor = root->left;
                // predecessor���ǵ�ǰ�ڵ�����һ����Ȼ��һֱ����ֱ���޷���Ϊֹ
                while (predecessor->right != nullptr && predecessor->right != root)
                    predecessor = predecessor->right;
                // ��predecessorָ��rootȻ���������������
                if (predecessor->right == nullptr)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                // ˵��������������ɣ���������������
                else
                {
                    predecessor->right = nullptr;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }   
        return ans; 
    }
};