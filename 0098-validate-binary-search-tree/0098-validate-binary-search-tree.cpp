class Solution {
public:
    bool res = 1;
    void dfs(TreeNode* root, long long int left, long long int right){
        if(!root){
            return;
        }
        if(!(left < (long long int)root->val && (long long int)root->val < right)){
            res = 0;
            return;
        }

        dfs(root->left, left, root->val);
        dfs(root->right, root->val, right);
    }

    bool isValidBST(TreeNode* root) {
        dfs(root, LONG_LONG_MIN, LONG_LONG_MAX);
        return res;
    }
};