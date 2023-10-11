class Solution {
public:
    int dp[5002][2];
    
    int maxProfit(vector<int>& prices) {
        int cooldown = 1;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int hold = 0; hold <= 1; hold++)
            {
                int take = 0;
                if(hold) {
                    take = prices[i] + dp[i + 1 + cooldown][0];
                }
                else {
                    take = -prices[i] + dp[i + 1][1];
                }
                int notTake = dp[i + 1][hold];
                dp[i][hold] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};