class Solution {
public:
    int dfs(TreeNode *root){
        if(!root){
            return 0;
        }
        
        TreeNode *l = root->left;
        int lDepth = 1;
        while(l){
            lDepth++;
            l = l->left;
        }
        TreeNode *r = root->right;
        int rDepth = 1;
        while(r){
            rDepth++;
            r = r->right;
        }

        if(lDepth == rDepth){
            return pow(2, lDepth) - 1;
        }

        return 1 + dfs(root->left) + dfs(root->right);
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        return dfs(root);
    }
};