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
class BSTIterator {
private:
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    vector<int> arr;
    int idx;
public:
    BSTIterator(TreeNode* root) : idx(0) {
        inorder(root);
     }
    
    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return idx < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */