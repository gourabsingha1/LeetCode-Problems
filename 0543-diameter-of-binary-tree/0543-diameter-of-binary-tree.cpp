class Solution {
public:
    int diameter(TreeNode* root, int &res) {
        // base condition
        if(!root){
            return 0;
        }

        // hypothesis
        int lHeight = diameter(root->left, res);
        int rHeight = diameter(root->right, res);

        // induction
        int temp = max(lHeight, rHeight) + 1; // the current node may not be the root of the diameter
        int ans = lHeight + rHeight; // the current node may be the root of the diameter
        res = max(res, ans); // finding the correct diamter

        return temp; // pass on the max height + 1 to check for the next nodes
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameter(root, res);
        return res;
    }
    
};