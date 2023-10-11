class Solution {
public:
    int dp[1001][2][101];

    int helper(int i, bool hold, int transactions, vector<int>& prices) {
        if(i == prices.size() || transactions == 0) {
            return 0;
        }
        if(dp[i][hold][transactions] != -1) {
            return dp[i][hold][transactions];
        }

        int take = 0;
        if(hold) {
            take = prices[i] + helper(i + 1, 0, transactions - 1, prices);
        }
        else {
            take = -prices[i] + helper(i + 1, 1, transactions, prices);
        }
        int notTake = helper(i + 1, hold, transactions, prices);
        return dp[i][hold][transactions] = max(take, notTake);
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, k, prices);
    }
};