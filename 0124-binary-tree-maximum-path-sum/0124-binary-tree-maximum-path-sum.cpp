class Solution {
public:
    int maxPathSumNLeaf(TreeNode* root, int &res){
        // base condition
        if(!root){
            return 0;
        }

        // hypothesis
        int lHeight = maxPathSumNLeaf(root->left, res);
        int rHeight = maxPathSumNLeaf(root->right, res);

        // induction
        int temp = max(root->val, max(lHeight, rHeight) + root->val); // root->val = +ve, lHeight = -ve, rHeight = -ve || root->val = +ve, lHeight/rHeight = +ve
        int ans = max(temp, lHeight + rHeight + root->val); // current node may be the root of the path which gives the maximum sum
        res = max(res, ans);

        return temp;
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumNLeaf(root, res);
        return res;
    }
};