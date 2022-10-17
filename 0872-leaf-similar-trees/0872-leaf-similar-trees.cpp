class Solution {
public:
    void Preorder(TreeNode *root, vector<int> &r){
        if(root == NULL){
            return;
        }
        if(!root->left && !root->right){
            r.push_back(root->val);
        }
        
        Preorder(root->left, r);
        Preorder(root->right, r);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;
        Preorder(root1, r1);
        Preorder(root2, r2);
        return r1 == r2;
    }
};