class Solution {
public:
    int maxPathSumNLeaf(TreeNode* root, int &res){
        // base condition
        if(!root){
            return 0;
        }

        // hypothesis
        int lHeight = max(0, maxPathSumNLeaf(root->left, res)); // want maximum
        int rHeight = max(0, maxPathSumNLeaf(root->right, res)); // want maximum

        // induction
        int temp = max(lHeight, rHeight) + root->val; // assuming root->val to be +ve. parent node will check whether or not
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