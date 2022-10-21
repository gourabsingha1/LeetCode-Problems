class Solution {
public:
    bool checkBST(TreeNode* root, long long int left, long long int right){
        // base condition
        if(!root){
            return 1;
        }
        if(!(left < (long long int)root->val && (long long int)root->val < right)){
            return 0;
        }

        // hypothesis
        bool checkLeft = checkBST(root->left, left, root->val); // check -inf < 1 < 5
        bool checkRight = checkBST(root->right, root->val, right); // check 5 < 7 < inf

        return checkLeft && checkRight; // if one of them is false, ans is false
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};