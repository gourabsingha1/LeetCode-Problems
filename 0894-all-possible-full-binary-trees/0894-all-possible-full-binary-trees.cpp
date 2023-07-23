class Solution {
public:
    vector<TreeNode*> helper(TreeNode* root, int n) {
        if(n == 1) {
            return {new TreeNode(0)};
        }

        vector<TreeNode*> res;
        for (int i = 1; i < n; i += 2)
        {
            // FBT's of left and right sides
            vector<TreeNode*> left = helper(root, i);
            vector<TreeNode*> right = helper(root, n - 1 - i);
            
            // combinations
            for(auto& l : left) {
                for(auto& r : right) {
                    root = new TreeNode(0);
                    root->left = l, root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) {
            return {};
        }
        TreeNode* root;
        return helper(root, n);
    }
};