class Solution {
public:
    int res = 0;
    void Preorder(TreeNode *root, int direction){
        if(root == NULL){
            return;
        }
        if(!direction && !root->left && !root->right){
            res += root->val;
        }
        
        Preorder(root->left, 0);
        Preorder(root->right, 1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        Preorder(root, -1);
        return res;
    }
};