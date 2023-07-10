class Solution {
public:
    int res = INT_MAX;

    void helper(int level, TreeNode* root) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            res = min(res, level);
        }
        
        helper(level + 1, root->left);
        helper(level + 1, root->right);
    }

    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        helper(1, root);
        return res;
    }
};