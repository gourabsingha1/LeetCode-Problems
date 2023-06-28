class Solution {
public:
    int dfs(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        int res = root->val + left + right;
        if(left == 0) {
            root->left = NULL;
        }
        if(right == 0) {
            root->right = NULL;
        }
        return res;
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if(root->val == 0 && !root->left && !root->right) {
            root = NULL;
        }
        return root;
    }
};