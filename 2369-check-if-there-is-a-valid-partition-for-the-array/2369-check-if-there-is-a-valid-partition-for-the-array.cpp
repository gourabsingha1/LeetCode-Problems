class Solution {
public:
    bool helper(int i, vector<int>& nums, vector<int>& dp) {
        if(i >= nums.size()) {
            return 1;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        bool res = 0;
        if(i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            res |= helper(i + 2, nums, dp);
        }
        if(i + 2 < nums.size() && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) {
            res |= helper(i + 3, nums, dp);
        }
        if(i + 2 < nums.size() && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2]) {
            res |= helper(i + 3, nums, dp);
        }
        return dp[i] = res;
    }
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};