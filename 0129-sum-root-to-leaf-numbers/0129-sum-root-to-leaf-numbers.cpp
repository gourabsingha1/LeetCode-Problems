class Solution {
public:
    int res = 0;
    void sumRTL(TreeNode* root, int sum){
        // base condition
        if(!root){
            return;
        }
        
        // induction
        sum = sum*10 + root->val;
        if(!root->left && !root->right){
            res += sum;
        }

        // hypothesis
        sumRTL(root->left, sum);
        sumRTL(root->right, sum);

        return;
    }
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }

        int sum = 0;
        sumRTL(root, sum);
        return res;
    }
};