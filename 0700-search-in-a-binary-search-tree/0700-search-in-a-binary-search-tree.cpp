class Solution {
public:
    TreeNode* res;
    void dfs(TreeNode* root, int val){
        if(!root){
            return;
        }
        if(root->val < val){
            searchBST(root->right, val);
        }
        else if(root->val > val){
            searchBST(root->left, val);
        }
        else{
            res = root;
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        dfs(root, val);
        return res;
    }
};