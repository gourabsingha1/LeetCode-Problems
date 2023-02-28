class Solution {
public:
    vector<TreeNode*> res;
    unordered_map<string, int> m, seen;
    void hashSubTree(string& hash, TreeNode* root, bool left) {
        if(!root){
            hash += "#";
            return;
        }
        hash += to_string(root->val) + "*" + to_string(left);
        hashSubTree(hash, root->left, 1);
        hashSubTree(hash, root->right, 0);
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        string hash;
        hashSubTree(hash, root, 0);
        m[hash]++;
        if(m[hash] > 1 && !seen[hash]) {
            res.push_back(root);
            seen[hash] = 1;
        }
        dfs(root->left);
        dfs(root->right);
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};