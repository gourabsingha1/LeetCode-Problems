class Solution {
public:
    vector<int> dfs(int &res, TreeNode* root){
        if(!root) return {0, 0};
        auto left = dfs(res, root->left);
        auto right = dfs(res, root->right);
        int sum = left[0] + right[0] + root->val;
        int n = left[1] + right[1] + 1;
        if(sum / n == root->val){
            res++;
        }
        return {sum, n};
    }
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        dfs(res, root);
        return res;
    }
};