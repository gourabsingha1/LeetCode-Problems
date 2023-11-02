class Solution {
public:
    int dfs(int sum, TreeNode* root, int& limit) {
        if(!root->left && !root->right) {
            return root->val;
        }
        
        int left = INT_MIN, right = INT_MIN;
        if(root->left) {
            left = dfs(sum + root->val, root->left, limit);
            if(root->val + sum + left < limit) {
                root->left = NULL;
            }
        }
        if(root->right) {
            right = dfs(sum + root->val, root->right, limit);
            if(root->val + sum + right < limit) {
                root->right = NULL;
            }
        }
        
        return root->val + max(left, right);
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(dfs(0, root, limit) < limit) {
            return NULL;
        }
        return root;
    }
};