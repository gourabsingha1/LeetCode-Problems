class Solution {
public:
    void Preorder(TreeNode *root, int targetSum, bool &res){
        // base condition
        if(!root){
            return;
        }
        targetSum -= root->val;

        // hypothesis
        Preorder(root->left, targetSum, res);
        Preorder(root->right, targetSum, res);
        
        // induction
        if(!root->left && !root->right && !targetSum){
            res = 1;
            return;
        }
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