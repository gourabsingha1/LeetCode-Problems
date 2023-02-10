class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int cnt){
        if(!root){
            res = max(res, cnt);
            return;
        }
        dfs(root->left, cnt + 1);
        dfs(root->right, cnt + 1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};