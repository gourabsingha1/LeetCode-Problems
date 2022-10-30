class Solution {
public:
    int cnt = 0, res = 0;
    void dfs(TreeNode* root, int k){
        if(!root){
            return;
        }
        dfs(root->left, k);
        cnt++;
        if(cnt == k){
            res = root->val;
            return;
        }
        dfs(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};