class Solution {
public:
    int res = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(!(root->left && root->left->val == root->val)){
            left = 0;
        }
        if(!(root->right && root->right->val == root->val)){
            right = 0;
        }
        int temp = max(left, right) + 1;
        res = max(res, left + right);
        return temp;
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};