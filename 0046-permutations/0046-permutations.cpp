class Solution {
public:
    void helper(int currInd, vector<int>& nums, vector<vector<int>> &res){
        int n = nums.size();
        if(currInd == n){
            res.push_back(nums);
            return;
        }
        for (int i = currInd; i < n; i++)
        {
            swap(nums[i], nums[currInd]);
            helper(currInd + 1, nums, res);
            swap(nums[i], nums[currInd]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0, nums, res);
        return res;
    }
};