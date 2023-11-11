// a node will return no. of moves its subtree requires
// if left < 0, left requires coins. else it has excess coins
// res += abs(left) + abs(right)

class Solution {
public:
    int res = 0;

    int helper(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int left = helper(root->left);
        int right = helper(root->right);
        res += abs(left) + abs(right);
        return left + right + root->val - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        helper(root);
        return res;
    }
};