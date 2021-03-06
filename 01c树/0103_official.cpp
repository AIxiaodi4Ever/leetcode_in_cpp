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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        bool isLeftOrder = true;
        while (!nodeQueue.empty())
        {
            deque<int> LevelList;
            int sz = nodeQueue.size();
            // 判断语句不能用nodeQueue.size()
            // 因为nodeQueue的大小一直在增加
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *temp = nodeQueue.front();
                nodeQueue.pop();
                if (isLeftOrder)
                    LevelList.push_back(temp->val);
                else
                    LevelList.push_front(temp->val);
                
                if (temp->left)
                    nodeQueue.push(temp->left);
                if (temp->right)
                    nodeQueue.push(temp->right);
            }
            isLeftOrder = !isLeftOrder;
            ans.emplace_back(vector<int>{LevelList.begin(), LevelList.end()});
        }
        return ans;
    }
};