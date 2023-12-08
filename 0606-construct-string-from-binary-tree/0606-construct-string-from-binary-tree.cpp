class Solution {
public:
    string helper(TreeNode* root) {
        string res = "(" + to_string(root->val);
        bool left = 0;
        if(root->left) {
            res += helper(root->left) + ")";
            left = 1;
        }
        if(root->right) {
            if(!left) {
                res += "()";
            }
            res += helper(root->right) + ")";
        }
        return res;
    }

    string tree2str(TreeNode* root) {
        string res = helper(root);
        return res.substr(1, res.size() - 1);
    }
};