class Solution {
public:
    pair<int, int> dfs(int &res, TreeNode* root){
        if(!root) return {0, 0};
        auto left = dfs(res, root->left);
        auto right = dfs(res, root->right);
        int sum = left.first + right.first + root->val;
        int n = left.second + right.second + 1;
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