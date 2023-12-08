// strong recursion background required

class Solution {
public:
    string helper(TreeNode* root) {
        string res = to_string(root->val);
        if(root->left) {
            res += "(" + helper(root->left) + ")";
        }
        if(root->right) {
            if(!root->left) {
                res += "()";
            }
            res += "(" + helper(root->right) + ")";
        }
        return res;
    }

    string tree2str(TreeNode* root) {
        return helper(root);
    }
};