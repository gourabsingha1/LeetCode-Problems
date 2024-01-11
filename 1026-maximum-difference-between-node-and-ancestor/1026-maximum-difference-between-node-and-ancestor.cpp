class Solution {
public:
    int res = 0;
    
    void dfs(TreeNode* root, int mi, int ma){
        if(!root) {
            res = max(res, abs(mi - ma));
            return;
        }
        
        mi = min(mi, root->val);
        ma = max(ma, root->val);
        dfs(root->left, mi, ma);
        dfs(root->right, mi, ma);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return res;
    }
};