class Solution {
public:
    void invert(TreeNode* root){
        if(!root){
            return;
        }
        swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
    }
    TreeNode* invertTree(TreeNode* root){
        invert(root);
        return root;
    }
};