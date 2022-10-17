class Solution {
public:
    int isBal(TreeNode* root, bool &res){
        // base condition
        if(!root){
            return 0;
        }

        // hypothesis
        int lHeight = isBal(root->left, res); // want maximum
        int rHeight = isBal(root->right, res); // want maximum

        // induction
        int temp = max(lHeight, rHeight) + 1;
        if(abs(lHeight - rHeight) > 1){
            res = 0;
            return 0;
        }
        return temp;
    }

    bool isBalanced(TreeNode* root) {
        bool res = 1;
        isBal(root, res);
        return res;
    }
};