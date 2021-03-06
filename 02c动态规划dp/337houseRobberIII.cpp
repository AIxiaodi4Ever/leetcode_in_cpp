/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
解题思路：动态规划+dfs
令f(o)表示选择节点o时的最大钱数，g(o)表示不选择节点o时的最大钱数。
令l和r分别为o的左儿子和右儿子，则：
f(o) = g(l) + g(r) + o->val;
g(o) = max(f(l), g(l)) + max(f(r), g(r));
从上式可以看出，o的状态只由它的两个儿子决定，因此由dfs进行后序遍历，
每次首先计算某一节点左右儿子选择和不选择两个状态的值，返回后计算当前节点。
节点为空时返回{0, 0}为基本情形。
*/

struct subTreeStatue{
    int selected;
    int unselected;
};


class Solution {
public:
    subTreeStatue myDfs(TreeNode *curr)
    {
        if (curr == nullptr)
            return {0, 0};
        subTreeStatue left = myDfs(curr->left);
        subTreeStatue right = myDfs(curr->right);

        int selected = curr->val + left.unselected + right.unselected;
        int unselected = max(left.selected, left.unselected) + 
            max(right.selected, right.unselected);
        return {selected, unselected};
    }

    int rob(TreeNode* root) 
    {
        subTreeStatue theRoot = myDfs(root);
        return max(theRoot.selected, theRoot.unselected);
    }
};