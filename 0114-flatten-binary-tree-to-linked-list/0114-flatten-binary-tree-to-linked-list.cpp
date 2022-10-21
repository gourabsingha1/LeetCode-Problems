class Solution {
public:
    vector<int> res;
    void Preorder(TreeNode *root){
        if(root == NULL){
            return;
        }
        res.push_back(root->val);
        Preorder(root->left);
        Preorder(root->right);
    }
    void flatten(TreeNode* root) {
        Preorder(root);

        for (int i = 1; i < res.size(); i++)
        {
            root->right = new TreeNode(res[i]);
            root->left = NULL;
            root = root->right;
        }
        
    }
};