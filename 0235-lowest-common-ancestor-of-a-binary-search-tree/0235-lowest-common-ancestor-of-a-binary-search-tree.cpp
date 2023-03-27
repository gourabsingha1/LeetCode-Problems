class Solution {
public:
    TreeNode* res;
    void dfs(TreeNode* root, int p, int q) {
        if(!root) {
            return;
        }
        if(p <= root->val && root->val <= q) {
            res = root;
            return;
        }
        dfs(root->left, p, q);
        dfs(root->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        }
        dfs(root, p->val, q->val);
        return res;
    }
};