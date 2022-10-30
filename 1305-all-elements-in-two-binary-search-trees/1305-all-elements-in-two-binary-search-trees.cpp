class Solution {
public:
    vector<int> res;
    void Inorder(TreeNode *root){
        if(root == NULL){
            return;
        }
        Inorder(root->left);
        res.push_back(root->val);
        Inorder(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        Inorder(root1), Inorder(root2);
        sort(res.begin(), res.end());
        return res;
    }
};