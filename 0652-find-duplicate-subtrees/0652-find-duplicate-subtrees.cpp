class Solution {
public:
    vector<TreeNode*> res;
    unordered_map<string, int> m;
    void hashSubTree(string& hash, TreeNode* root) {
        if(!root){
            hash += "#";
            return;
        }
        hash += to_string(root->val) + "*";
        hashSubTree(hash, root->left);
        hashSubTree(hash, root->right);
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        string hash;
        hashSubTree(hash, root);
        m[hash]++;
        if(m[hash] > 1) {
            res.push_back(root);
            m[hash] = -1e9;
        }
        dfs(root->left);
        dfs(root->right);
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};