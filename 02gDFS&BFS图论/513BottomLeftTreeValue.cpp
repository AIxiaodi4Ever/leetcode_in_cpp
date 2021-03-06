/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 题解的人都太有才了。。
// BSF不过先让右子树入列，最后返回的就是最后一层的最左边。
// 咋就没想到树的正常层序遍历会返回最后一层最右边呢

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