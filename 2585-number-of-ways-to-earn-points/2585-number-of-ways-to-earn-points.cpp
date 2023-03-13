class Solution {
public:
    // memoization
    int M = 1e9 + 7;
    int helper(int n, vector<vector<int>>& types, int target, vector<vector<int>>& dp) {
        if(target == 0) {
            return 1;
        }
        if(n < 0 || target < 0) {
            return 0;
        }
        if(dp[n][target] != -1) {
            return dp[n][target];
        }
        int take = 0;
        for (int i = 1; i <= types[n][0]; i++)
        {
            take = (take + helper(n - 1, types, target - i * types[n][1], dp)) % M;
        }
        int notTake = helper(n - 1, types, target, dp);
        return dp[n][target] = (take + notTake) % M;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        return helper(n - 1, types, target, dp);
    }
};