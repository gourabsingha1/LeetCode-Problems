// find the freq of 1 mode first using dfs1. then find all modes using dfs2

class Solution {
public:
    unordered_map<int, int> freq;
    int mx = 0;
    
    void dfs1(TreeNode* root) {
        if(!root) {
            return;
        }

        mx = max(mx, ++freq[root->val]);
        dfs1(root->left);
        dfs1(root->right);
    }
    
    vector<int> res;

    void dfs2(TreeNode* root) {
        if(!root) {
            return;
        }

        if(mx == freq[root->val]) {
            res.push_back(root->val);
            freq[root->val] = 0;
        }
        dfs2(root->left);
        dfs2(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs1(root);
        dfs2(root);
        return res;
    }
};