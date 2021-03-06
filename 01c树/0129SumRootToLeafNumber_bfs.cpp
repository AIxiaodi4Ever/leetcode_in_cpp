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
    int sumNumbers(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> nodesQueue;
        queue<int> sumsQueue;

        nodesQueue.push(root);
        sumsQueue.push(root->val);

        int sum = 0;
        while (!nodesQueue.empty())
        {
            TreeNode* currNode = nodesQueue.front();
            int num = sumsQueue.front();
            nodesQueue.pop();
            sumsQueue.pop();
            if (currNode->left == nullptr && currNode->right == nullptr)
                sum += num;
            if (currNode->left)
            {
                nodesQueue.push(currNode->left);
                sumsQueue.push(num * 10 + currNode->left->val);
            }
            if (currNode->right)
            {
                nodesQueue.push(currNode->right);
                sumsQueue.push(num * 10 + currNode->right->val);
            }
        }
        return sum;
    }
};