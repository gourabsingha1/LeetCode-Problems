class Solution {
public:
    long long int sum = 0, res = 0, M = 1e9 + 7;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int cur = left + right + root->val;
        res = max(res, (sum - cur)*cur);
        return cur;
    }

    int maxProduct(TreeNode* root) {
        sum = dfs(root);
        dfs(root);
        return res%M;
    }
};