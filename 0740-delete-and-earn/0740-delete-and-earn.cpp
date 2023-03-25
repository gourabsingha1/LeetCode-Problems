class Solution {
public:
    // memoization
    int helper(int n, vector<int> mp, vector<int>& dp) {
        if(n < 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int take = n * mp[n] + helper(n - 2, mp, dp);
        int notTake = helper(n - 1, mp, dp);
        return dp[n] = max(take, notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> mp(10001, 0);
        int maxElement = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            maxElement = max(maxElement, nums[i]);
        }
        vector<int> dp(maxElement + 1, -1);
        return helper(maxElement, mp, dp);
    }
};