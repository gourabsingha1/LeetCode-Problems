class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int cur, int left) {
        res = max(res, cur);
        if(root->left) {
            if(left != 0) {
                dfs(root->left, cur + 1, 0);
            }
            else {
                dfs(root->left, 1, 0);
            }
        }
        if(root->right) {
            if(left != 1) {
                dfs(root->right, cur + 1, 1);
            }
            else {
                dfs(root->right, 1, 1);
            }
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, 0, -1);
        return res;
    }
};