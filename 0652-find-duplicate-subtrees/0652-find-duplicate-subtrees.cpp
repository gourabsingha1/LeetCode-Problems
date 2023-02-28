class Solution {
public:
    vector<TreeNode*> res;
    unordered_map<string, int> m;
    string serialize(TreeNode* root) {
        if(!root) {
            return "n";
        }
        string s = "[" + serialize(root->left) + "," + to_string(root->val) + "," + serialize(root->right) + "]";
        if(m[s] == 1) {
            res.push_back(root);
        }
        m[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }
};