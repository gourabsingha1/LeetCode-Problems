class Solution {
public:
    vector<int> nums;
    void dfs(TreeNode *root){
        if(!root){
            return;
        }
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int high = nums.size()-1, low = 0;
        while(low<high){
            if(nums[low] + nums[high] == k){
                return 1;
            }
            else if(nums[low] + nums[high] > k){
                high--;
            }
            else{
                low++;
            }
        }
        return 0;
    }
};