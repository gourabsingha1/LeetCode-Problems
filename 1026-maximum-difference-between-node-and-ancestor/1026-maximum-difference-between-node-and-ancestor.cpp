class Solution {
public:
    int dfs(TreeNode* root, int mi, int ma){
        if(!root) return abs(mi - ma);
        
        mi = min(mi, root->val);
        ma = max(ma, root->val);
        
        int left = dfs(root->left, mi, ma);
        int right = dfs(root->right, mi, ma);

        return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};