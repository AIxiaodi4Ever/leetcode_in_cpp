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
    int countNodes(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        int level = 0;
        TreeNode *tmp = root;
        // 根是0，所以这里得是tmp->left
        while (tmp->left != nullptr)
        {
            ++level;
            tmp = tmp->left;
        }
        int numsMin = 1 << level;
        int numsMax = (1 << (level + 1)) - 1;
        while (numsMin < numsMax)
        {
            // +1 is necessary otherwise the circle wound't stop
            // cause if pathNotBigger return true we only can updata numsMin to mid
            // but if return false we can surely updata numsMax to mid - 1
            int mid = numsMin + (numsMax - numsMin + 1) / 2;
            if (pathNotBigger(root, level, mid))
                numsMin = mid;
            else
                numsMax = mid - 1;
        }
        return numsMin;
    }

    bool pathNotBigger(TreeNode* root, int level, int k)
    {
        int bits = 1 << (level - 1);
        TreeNode *tmp = root;
        while (tmp != nullptr && bits > 0)
        {
            if (bits & k)
                tmp = tmp->right;
            else
                tmp = tmp->left;
            bits >>= 1;
        }
        return tmp != nullptr;
    }
};