class Solution {
public:
    int M = 1e9 + 7;
    int helper(int pSum, int i, int n, int minProfit, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp) {
        if(n < 0) {
            return 0;
        }
        if(i == profit.size()) {
            return minProfit <= pSum;
        }
        if(dp[i][n][pSum] != -1) {
            return dp[i][n][pSum];
        }

        int take = helper(min(pSum + profit[i], minProfit), i + 1, n - group[i], minProfit, group, profit, dp);
        int notTake = helper(pSum, i + 1, n, minProfit, group, profit, dp);
        return dp[i][n][pSum] = (take + notTake) % M;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(profit.size(), vector<vector<int>> (n + 1, vector<int> (minProfit + 1, -1)));
        return helper(0, 0, n, minProfit, group, profit, dp);
    }
};