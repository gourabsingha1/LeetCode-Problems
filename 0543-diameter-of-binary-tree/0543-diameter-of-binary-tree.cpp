class Solution {
public:
    int res = 0;
    
    int helper(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int leftHeight = helper(root->left);
        int rightHeight = helper(root->right);
        res = max(res, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return res;
    }
};