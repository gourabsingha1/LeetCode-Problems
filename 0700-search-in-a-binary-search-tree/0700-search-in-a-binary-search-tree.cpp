class Solution {
public:
    TreeNode* res;
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return root;
        }
        if(root->val < val){
            res = searchBST(root->right, val);
        }
        else if(root->val > val){
            res = searchBST(root->left, val);
        }
        else{
            return root;
        }
        return res;
    }
};