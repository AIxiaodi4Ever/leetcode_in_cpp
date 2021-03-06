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
class Solution {
public:
    void addPath(vector<int> &vec, TreeNode *node)
    {
        vector<int> tmp;
        while (node != nullptr)
        {
            tmp.emplace_back(node->val);
            node = node->right;
        }
        reverse(tmp.begin(), tmp.end());
        for (int &v : tmp)
        {
            vec.emplace_back(v);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr)
        {
            p2 = p1->left;
            if (p2 != nullptr)
            {
                while (p2->right != nullptr && p2->right != p1)
                    p2 = p2->right;
                if (p2->right == nullptr)
                {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }
                else
                {
                    p2->right = nullptr;
                    addPath(ans, p1->left);
                }
            }
            p1 = p1->right;
        }
        addPath(ans, root);
        return ans;
    }
};