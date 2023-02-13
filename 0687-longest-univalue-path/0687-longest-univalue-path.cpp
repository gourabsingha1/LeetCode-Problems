class Solution {
public:
    int res = 0;
    int dfs(int parent, TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->val, root->left);
        int right = dfs(root->val, root->right);
        int temp = max(left, right) + 1;
        if(root->val != parent){
            temp = 0;
        }
        res = max(res, left + right);
        return temp;
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(-1, root);
        return res;
    }
};