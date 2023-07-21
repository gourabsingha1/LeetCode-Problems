class Solution {
public:
    int helper(int j, int i, vector<int>& nums, vector<vector<int>>& dp) {
        if(j == nums.size()) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int take = 0;
        if(nums[i] < nums[j]) {
            take = 1 + helper(j + 1, j, nums, dp);
        }
        int notTake = helper(j + 1, i, nums, dp);
        return dp[i][j] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        for (int i = 0; i < n; i++)
        {
            res = max(res, helper(i + 1, i, nums, dp));
        }
        return res;
    }
};