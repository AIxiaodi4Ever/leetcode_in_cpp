/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every 
node never differ by more than 1.

Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [0]
Output: [0]

Example 4:
Input: head = [1,3]
Output: [3,1]

Constraints:
    The numner of nodes in head is in the range [0, 2 * 10^4].
    -10^5 <= Node.val <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getLength(ListNode* head)
    {
        int ret = 0;
        for (; head != nullptr; ++ret)
            head = head->next;
        return ret;
    }
    // 这里的传引用是深思熟虑啊。。。。
    TreeNode* buildTree(ListNode*& head, int left, int right)
    {
        if (left > right)
            return nullptr;
        TreeNode* root = new TreeNode();
        int mid = (left + right + 1) / 2;
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        // head忘记递增
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        int len = getLength(head);
        return buildTree(head, 0, len - 1);
    }
};