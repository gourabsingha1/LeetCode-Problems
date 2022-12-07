class Solution {
public:
    int res = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root){
            return 0;
        }
        rangeSumBST(root->left, low, high);
        if(root->val >= low && root->val <= high){
            res += root->val;
        }
        rangeSumBST(root->right, low, high);
        return res;
    }
};