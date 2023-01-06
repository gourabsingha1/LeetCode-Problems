class Solution {
public:
    void dfs(TreeNode* root, string s, string &res){
        if(!root) return;
        
        if(!root->left && !root->right){
            res = min(res, (char)(root->val + 'a') + s);
            return;
        }
        dfs(root->left, (char)(root->val + 'a') + s, res);
        dfs(root->right, (char)(root->val + 'a') + s, res);
    }

    string smallestFromLeaf(TreeNode* root) {
        string res = "{";
        dfs(root, "", res);
        return res;
    }
};