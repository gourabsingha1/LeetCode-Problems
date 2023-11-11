// for every node, consider that the path goes through it
// return max(0, root->val + max(leftSum, rightSum)) to parent
// 0 to exclude the path

class Solution {
public:
    int res = INT_MIN;

    int helper(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        res = max(res, leftSum + root->val + rightSum);
        return max(0, root->val + max(leftSum, rightSum));
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;
    }
};