// first loop: select the root node
// second loop: recursively select the left tree
// third loop: recursively select the right tree
// add the root to res

class Solution {
public:
    vector<TreeNode*> helper(int left, int right) {
        if(left > right) {
            return {NULL};
        }

        vector<TreeNode*> res;
        for (int val = left; val <= right; val++)
        {
            vector<TreeNode*> leftHelper = helper(left, val - 1);
            vector<TreeNode*> rightHelper = helper(val + 1, right);
            for(auto& leftTree : leftHelper) {
                for(auto& rightTree : rightHelper) {
                    TreeNode* root = new TreeNode(val, leftTree, rightTree);
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};