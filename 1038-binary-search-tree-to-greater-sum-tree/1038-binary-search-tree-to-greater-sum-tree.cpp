class Solution {
public:
    void inOrder(TreeNode* root, int& sum) {
        if(!root) {
            return;
        }
        inOrder(root->right, sum);
        sum += root->val;
        root->val = sum;
        inOrder(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        inOrder(root, sum);
        return root;
    }
};