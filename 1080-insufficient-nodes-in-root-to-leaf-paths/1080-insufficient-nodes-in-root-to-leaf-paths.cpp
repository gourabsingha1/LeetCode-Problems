// get the sum from up and down (left & right)
// if sum + left < limit, root->left = NULL

class Solution {
public:
    int dfs(int sum, TreeNode* root, int& limit) {
        if(!root->left && !root->right) {
            return root->val;
        }
        
        int left = INT_MIN, right = INT_MIN;
        if(root->left) {
            left = dfs(sum + root->left->val, root->left, limit);
            if(sum + left < limit) {
                root->left = NULL;
            }
        }
        if(root->right) {
            right = dfs(sum + root->right->val, root->right, limit);
            if(sum + right < limit) {
                root->right = NULL;
            }
        }
        
        return root->val + max(left, right);
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(dfs(root->val, root, limit) < limit) {
            return NULL;
        }
        return root;
    }
};