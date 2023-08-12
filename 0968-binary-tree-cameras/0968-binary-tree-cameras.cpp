class Solution {
public:
    int noCamera = -1, hasCamera = 0, notNeeded = 1;
    int res = 0;

    int helper(TreeNode* root) {
        if(!root) {
            return notNeeded;
        }

        int leftChild = helper(root->left);
        int rightChild = helper(root->right);
        if(leftChild == noCamera || rightChild == noCamera) {
            res++;
            return hasCamera;
        }
        if(leftChild == hasCamera || rightChild == hasCamera) {
            return notNeeded;
        }
        return noCamera;
    }

    int minCameraCover(TreeNode* root) {
        if(helper(root) == noCamera) res++;
        return res;
    }
};