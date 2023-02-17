class Solution {
public:
    int res = INT_MAX, prev = -1e6;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        res = min(res, root->val - prev);
        prev = root->val;
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return res;
    }
};