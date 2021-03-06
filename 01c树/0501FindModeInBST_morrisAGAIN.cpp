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
    int base, count, maxcount;
    vector<int> ans;

    void updata(int x)
    {
        if (x == base)
            ++count;
        else
        {
            count = 1;
            base = x;
        }
        if (count == maxcount)
            ans.push_back(base);
        if (count > maxcount)
        {
            ans = vector<int> {base};
            maxcount = count;
        }
        
    }

    vector<int> findMode(TreeNode* root) 
    {
        // 一开始base、count、maxcount都定义在全局作用域，所以原本都是0
        count = maxcount = 0;
        // base一开始可以等于任何数，所以没必要赋初值
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                updata(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode* predecessor;
                predecessor = cur->left;
                while (predecessor->right != nullptr && predecessor->right != cur)
                    predecessor = predecessor->right;
                if (predecessor->right == nullptr)
                {
                    predecessor->right = cur;
                    cur = cur->left;
                }
                // 剩下只可能指向当前节点
                else 
                {
                    predecessor->right = nullptr;
                    updata(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};