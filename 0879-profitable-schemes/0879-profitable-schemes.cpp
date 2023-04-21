class Solution {
public:
    int M = 1e9 + 7;
    int helper(int i, int n, int minProfit, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp) {
        if(n < 0) {
            return 0;
        }
        if(i == profit.size()) {
            return minProfit == 0;
        }
        if(dp[i][n][minProfit] != -1) {
            return dp[i][n][minProfit];
        }

        int take = helper(i + 1, n - group[i], max(0, minProfit - profit[i]), group, profit, dp);
        int notTake = helper(i + 1, n, minProfit, group, profit, dp);
        return dp[i][n][minProfit] = (take + notTake) % M;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(profit.size(), vector<vector<int>> (n + 1, vector<int> (minProfit + 1, -1)));
        return helper(0, n, minProfit, group, profit, dp);
    }
};