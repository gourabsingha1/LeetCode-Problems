class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return 1;
        }
        if(!p && q || p && !q || p->val != q->val){
            return 0;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return 0;
        }
        if(root->val == subRoot->val && isSameTree(root, subRoot)){
            return 1;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};