class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int sum){
        if(!root){
            return;
        }
        sum = sum * 10 + root->val;
        if(!root->left && !root->right){
            res += sum;
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};