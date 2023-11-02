class Solution {
public:
    int res = 0;
    
    pair<int, int> dfs(TreeNode* root){
        if(!root) {
            return {0, 0};
        }
        
        auto [lSum, lSize] = dfs(root->left);
        auto [rSum, rSize] = dfs(root->right);
        int sum = root->val + lSum + rSum;
        int size = 1 + lSize + rSize;
        if(sum / size == root->val){
            res++;
        }
        return {sum, size};
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};