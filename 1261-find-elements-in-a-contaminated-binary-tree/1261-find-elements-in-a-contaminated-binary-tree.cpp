class FindElements {
public:
    unordered_map<int,int> m;
    void dfs(TreeNode *root, int x){
        if(root == NULL){
            return;
        }
        root->val = x;
        m[x] = 1;

        dfs(root->left, 2*x + 1);
        dfs(root->right, 2*x + 2);
    }
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return m[target];
    }
};