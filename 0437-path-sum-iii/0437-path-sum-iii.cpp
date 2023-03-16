class Solution {
public:
    int res = 0;
    void dfs1(TreeNode* root, int& targetSum) {
        if(!root) {
            return;
        }
        dfs2(root->val, root, targetSum);
        dfs1(root->left, targetSum);
        dfs1(root->right, targetSum);
    }
    void dfs2(long long sum, TreeNode* root, int& targetSum) {
        if(sum == targetSum) {
            res++;
        }
        if(root->left) {
            dfs2(sum + root->left->val, root->left, targetSum);
        }
        if(root->right) {
            dfs2(sum + root->right->val, root->right, targetSum);
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        dfs1(root, targetSum);
        return res;
    }
};