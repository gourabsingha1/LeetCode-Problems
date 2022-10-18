class Solution {
public:
    int cnt = 0;
    void dfs(TreeNode *root){
        if(!root){
            return;
        }
        cnt++;
        dfs(root->left);
        dfs(root->right);
    }
    int countNodes(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};