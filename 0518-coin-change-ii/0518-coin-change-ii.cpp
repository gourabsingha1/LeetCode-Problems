class Solution {
public:
    // tabulation
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if(i == 0) {
                    dp[i][j] = j % coins[i] == 0;
                }
                else {
                    int take = 0;
                    if(j - coins[i] >= 0) {
                        take = dp[i][j - coins[i]];
                    }
                    int notTake = dp[i - 1][j];
                    dp[i][j] = take + notTake;
                }
            }
        }
        return dp[n - 1][amount];
    }
};