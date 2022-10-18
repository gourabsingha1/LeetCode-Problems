class Solution {
public:
    int dfs(TreeNode *root){
        if(!root){
            return 0;
        }
        
        // count no. of left nodes of root
        TreeNode *l = root->left;
        int lDepth = 1;
        while(l){
            lDepth++;
            l = l->left;
        }
        
        // count no. of right nodes of root
        TreeNode *r = root->right;
        int rDepth = 1;
        while(r){
            rDepth++;
            r = r->right;
        }

        if(lDepth == rDepth){
            return pow(2, lDepth) - 1; // formula for PBT
        }

        return 1 + dfs(root->left) + dfs(root->right); // 1 for the node itself
    }
    int countNodes(TreeNode* root) {
        return dfs(root);
    }
};