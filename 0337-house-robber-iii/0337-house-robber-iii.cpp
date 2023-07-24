class Solution {
public:
    map<pair<bool, TreeNode*>, int> dp;
    
    int helper(bool flag, TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(dp.find({flag, root}) != dp.end()) {
            return dp[{flag, root}];
        }

        int take = 0, notTake = 0;
        if(!flag) {
            take = root->val + helper(!flag, root->left) + helper(!flag, root->right);
            notTake = helper(flag, root->left) + helper(flag, root->right);
        }
        else {
            notTake = helper(!flag, root->left) + helper(!flag, root->right);
        }
        return dp[{flag, root}] = max(take, notTake);
    }

    int rob(TreeNode* root) {
        return helper(0, root);
    }
};