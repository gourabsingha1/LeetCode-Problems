class Solution {
public:
    bool validateBST(TreeNode* root, long min, long max)
    {
        if(!root){
            return 1;
        }

        if(root->val <= min || root->val >= max){
            return 0;
        }
        
        return validateBST(root->left, min, root->val) && validateBST(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }
};