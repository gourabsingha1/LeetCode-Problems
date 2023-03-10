class Solution {
public:
    // memoization
    int helper(int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(n == 0 || amount == 0) {
            if(amount % coins[n] == 0) {
                return amount / coins[n];
            }
            return 1e9;
        }
        if(dp[n][amount] != -1) {
            return dp[n][amount];
        }
        int take = 1e9;
        if(amount - coins[n] >= 0) {
            take = 1 + helper(n, coins, amount - coins[n], dp);
        }
        int notTake = 0 + helper(n - 1, coins, amount, dp);
        return dp[n][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        int res = helper(coins.size() - 1, coins, amount, dp);
        if(res == 1e9) {
            res = -1;
        }
        return res;
    }
};