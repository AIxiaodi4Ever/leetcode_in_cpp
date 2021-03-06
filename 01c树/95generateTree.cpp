// leetcode:95
/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 
Constraints:
    0 <= n <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


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
    vector<TreeNode*> generateTrees(int start, int end)
    {
        if (start > end)
            return { nullptr };
        
        else
        {
            vector<TreeNode*> allTree;
            // 枚举所有根节点
            for (int i = start; i <= end; i++)
            {
                // 生成所有左子树
                vector<TreeNode*> leftTree = generateTrees(start, i - 1);
                // 生成所有右子树
                vector<TreeNode*> rightTree = generateTrees(i + 1, end);

                // 结合所有左右子树
                for (auto& left : leftTree)
                {
                    for(auto& right : rightTree)
                    {
                        TreeNode *curr = new TreeNode(i);
                        curr->left = left;
                        curr->right = right;
                        allTree.push_back(curr);
                    }
                }
            }
            return allTree;
        }
    }

    vector<TreeNode*> generateTrees(int n) 
    {
        if (!n)
            return {};
        else
            return generateTrees(1, n);
    }
};