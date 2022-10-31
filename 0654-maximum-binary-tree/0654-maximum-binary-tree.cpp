class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int start, int end){
        if(start == end){
            return new TreeNode(nums[start]);
        }
        else if(start > end){
            return NULL;
        }
        int ind = findMax(nums, start, end);
        TreeNode *root = new TreeNode(nums[ind]);
        root->left = buildTree(nums, start, ind-1);
        root->right = buildTree(nums, ind+1, end);
        return root;
    }
    int findMax(vector<int>& nums, int start, int end){
        int res = INT_MIN, ind = 0;
        for (int i = start; i <= end; i++)
        {
            if(nums[i] > res){
                res = nums[i];
                ind = i;
            }
        }
        return ind;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};