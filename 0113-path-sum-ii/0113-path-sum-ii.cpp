class Solution {
public:
    void dfs(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>> &res){
        if(!root) return;
        
        path.push_back(root->val);
        if(!root->left && !root->right && targetSum == root->val){
            res.push_back(path);
            return;
        }
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