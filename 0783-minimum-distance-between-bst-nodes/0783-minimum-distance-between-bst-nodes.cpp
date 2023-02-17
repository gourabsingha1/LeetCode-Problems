class Solution {
public:
    vector<int> nums;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        inorder(root);
        for (int i = 1; i < nums.size(); i++)
        {
            res = min(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};