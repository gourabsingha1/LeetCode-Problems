class Solution {
public:
    void dfs(TreeNode* root, string s, vector<string> &res){
        if(!root) return;
        
        if(!root->left && !root->right){
            res.push_back(s + to_string(root->val));
            return;
        }
        dfs(root->left, s + to_string(root->val) + "->", res);
        dfs(root->right, s + to_string(root->val) + "->", res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};