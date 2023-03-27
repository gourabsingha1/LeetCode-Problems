class Solution {
public:
    TreeNode* dfs(TreeNode* root, int p, int q) {
        if(!root) {
            return NULL;
        }
        if(root->val == p || root->val == q) {
            return root;
        }
        TreeNode *left = dfs(root->left, p, q), *right = dfs(root->right, p, q);
        if(left && right) {
            return root;
        }
        else if(left) {
            return left;
        }
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p->val, q->val);
    }
};