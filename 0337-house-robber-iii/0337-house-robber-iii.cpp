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
        // if last node was not taken (flag == 0), either take current node or dont
        if(!flag) {
            take = root->val + helper(!flag, root->left) + helper(!flag, root->right);
            notTake = helper(flag, root->left) + helper(flag, root->right);
        }
        // if last node was taken, let the next call decide whether take/notTake
        else {
            notTake = helper(!flag, root->left) + helper(!flag, root->right);
        }
        return dp[{flag, root}] = max(take, notTake);
    }

    int rob(TreeNode* root) {
        return helper(0, root);
    }
};