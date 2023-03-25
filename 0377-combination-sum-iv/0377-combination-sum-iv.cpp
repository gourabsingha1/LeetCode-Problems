class Solution {
public:
    // memoization
    int helper(int n, vector<int>& nums, int target, vector<int>& dp) {
        if(target == 0) {
            return 1;
        }
        if(n < 0 || target < 0) {
            return 0;
        }
        if(dp[target] != -1) {
            return dp[target];
        }
        int take = helper(nums.size() - 1, nums, target - nums[n], dp);
        int notTake = helper(n - 1, nums, target, dp);
        return dp[target] = take + notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return helper(nums.size() - 1, nums, target, dp);
    }
};