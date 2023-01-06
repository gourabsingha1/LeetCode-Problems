class Solution {
public:
    void dfs(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>> &res){
        if(!root) return;
        
        if(!root->left && !root->right && targetSum == root->val){
            path.push_back(root->val);
            res.push_back(path);
            return;
        }
        path.push_back(root->val);
        dfs(root->left, targetSum - root->val, path, res);
        dfs(root->right, targetSum - root->val, path, res);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        dfs(root, targetSum, {}, res);
        return res;
    }
};