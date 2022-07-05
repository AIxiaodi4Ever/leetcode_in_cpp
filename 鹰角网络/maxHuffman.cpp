/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

struct NodeInf {
    NodeInf(long long v, int s) : val(v), sz(s) {}
    long long val;
    int sz;
};

/* 寻找最大huffman树 */
// 和寻找最大BST同一个思路，不过这里只需要存储两个信息，不必存储该子树值的范围
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    
    int ans = 0;
    
    NodeInf dfs(TreeNode* root) {
        NodeInf cur(root->val, 1);
        // 出度为0时直接返回该节点的权值与大小1
        if (root->left == nullptr && root->right == nullptr) {
            ans = max(ans, cur.sz);
            return cur;
        }
        NodeInf L(-1, -1), R(-1, -1);
        if (root->left) {
            L = dfs(root->left);
        }
        if (root->right) {
            R = dfs(root->right);
        }
        // 出度为1，不是huffmanTree的节点，返回sz=-1
        if (L.sz == -1 || R.sz == -1) {
            cur.sz = -1;
            return cur;
        }
        // 出度为2，考虑根节点的权值是否是左右儿子的权值和
        cur.sz = cur.val == (L.val + R.val) ? (cur.sz + L.sz + R.sz) : -1;
        ans = max(ans, cur.sz);
        return cur;
    }
    
    int maxHuffman(TreeNode* root) {
        // write code here
        if (root == nullptr) {
            return 0;
        }
        dfs(root);
        return ans;
    }
};