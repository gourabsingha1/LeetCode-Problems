// inorder sorted traversal, res = min(res, cur - prev)
class Solution {
public:
    int res = INT_MAX, prev = -1e5;
    void inorder(TreeNode* root){
        if(!root) {
            return;
        }
        inorder(root->left);
        res = min(res, root->val - prev);
        prev = root->val;
        inorder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }
};