class Solution {
public:
    int dp[100001][2][2];

    int helper(int i, bool hold, int transactions, vector<int>& prices) {
        if(i == prices.size() || transactions == -1) {
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

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, 1, prices);
    }
};