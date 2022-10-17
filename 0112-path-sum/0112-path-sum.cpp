class Solution {
public:
    void Preorder(TreeNode *root, int targetSum, bool &res){
        // base condition
        if(!root){
            return;
        }
        if(!root->left && !root->right && targetSum == root->val){
            res = 1;
            return;
        }
        
        // induction
        targetSum -= root->val;

        // hypothesis
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