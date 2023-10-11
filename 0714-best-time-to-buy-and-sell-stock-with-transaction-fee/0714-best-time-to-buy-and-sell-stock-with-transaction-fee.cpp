class Solution {
public:
    int dp[50001][2];

    int helper(int i, bool hold, vector<int>& prices, int& fee) {
        if(i == prices.size()) {
            return 0;
        }
        if(dp[i][hold] != -1) {
            return dp[i][hold];
        }

        int take = 0;
        if(hold) {
            take = prices[i] - fee + helper(i + 1, 0, prices, fee);
        }
        else {
            take = -prices[i] + helper(i + 1, 1, prices, fee);
        }
        int notTake = helper(i + 1, hold, prices, fee);
        return dp[i][hold] = max(take, notTake);
    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, prices, fee);
    }
};