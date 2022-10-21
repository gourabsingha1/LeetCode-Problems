class FindElements {
public:
    unordered_map<int,int> m;
    void dfs(TreeNode *root){
        if(root == NULL){
            return;
        }
        if(root->left){
            root->left->val = root->val*2 + 1;
            m[root->left->val] = 1;
        }
        if(root->right){
            root->right->val = root->val*2 + 2;
            m[root->right->val] = 1;
        }
        dfs(root->left);
        dfs(root->right);
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        m[0] = 1;
        dfs(root);
    }
    
    bool find(int target) {
        return m[target];
    }
};