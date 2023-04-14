class Solution {
public:
    // memoization
    bool helper(int n, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(!sum) {
            return 1;
        }
        if(n < 0 || sum < 0) {
            return 0;
        }
        if(dp[n][sum] != -1) {
            return dp[n][sum];
        }
        bool take = helper(n - 1, sum - nums[n], nums, dp);
        bool notTake = helper(n - 1, sum, nums, dp);
        return dp[n][sum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        return helper(n - 1, sum / 2, nums, dp);
    }
};