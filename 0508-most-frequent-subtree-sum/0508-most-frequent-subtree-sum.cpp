// brute force

class Solution {
public:
    unordered_map<int, int> freq;
    int mx = 0;

    int helper(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int left = helper(root->left);
        int right = helper(root->right);
        int res = root->val + left + right;
        mx = max(mx, ++freq[res]);
        return res;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        helper(root);
        for(auto& [x, y] : freq) {
            if(y == mx) {
                res.push_back(x);
            }
        }
        return res;
    }
};