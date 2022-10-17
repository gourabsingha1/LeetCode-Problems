class Solution {
public:
    void Preorder(TreeNode *root, int targetSum, bool &res){
        if(root == NULL){
            return;
        }
        targetSum -= root->val;
        if(!root->left && !root->right && !targetSum){
            res = 1;
            return;
        }
        Preorder(root->left, targetSum, res);
        Preorder(root->right, targetSum, res);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = 0;
        if(!root){
            return res;
        }
        
        Preorder(root, targetSum, res);
        return res;
    }
};