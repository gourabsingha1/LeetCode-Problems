class Solution {
public:
    // memoization
    int helper(int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(n == 0 || amount == 0) {
            return amount % coins[n] == 0;
        }
        if(dp[n][amount] != -1) {
            return dp[n][amount];
        }
        int take = 0;
        if(amount - coins[n] >= 0) {
            take = helper(n, coins, amount - coins[n], dp);
        }
        int notTake = helper(n - 1, coins, amount, dp);
        return dp[n][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        return helper(coins.size() - 1, coins, amount, dp);
    }
};