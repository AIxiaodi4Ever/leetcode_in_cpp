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
����˼·����̬�滮+dfs
��f(o)��ʾѡ��ڵ�oʱ�����Ǯ����g(o)��ʾ��ѡ��ڵ�oʱ�����Ǯ����
��l��r�ֱ�Ϊo������Ӻ��Ҷ��ӣ���
f(o) = g(l) + g(r) + o->val;
g(o) = max(f(l), g(l)) + max(f(r), g(r));
����ʽ���Կ�����o��״ֻ̬�������������Ӿ����������dfs���к��������
ÿ�����ȼ���ĳһ�ڵ����Ҷ���ѡ��Ͳ�ѡ������״̬��ֵ�����غ���㵱ǰ�ڵ㡣
�ڵ�Ϊ��ʱ����{0, 0}Ϊ�������Ρ�
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