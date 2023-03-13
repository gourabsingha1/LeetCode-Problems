class Solution {
public:
    // memoization
    int helper(int n, vector<vector<int>>& piles, int k, vector<vector<int>>& dp) {
        if(k == 0 || n < 0) {
            return 0;
        }
        if(dp[n][k] != -1) {
            return dp[n][k];
        }
        int take = 0, sum = 0;
        for (int i = 0; i < piles[n].size() && k - i - 1 >= 0; i++)
        {
            sum += piles[n][i]; // prefix sum
            take = max(take, sum + helper(n - 1, piles, k - i - 1, dp));
        }
        int notTake = helper(n - 1, piles, k, dp);
        return dp[n][k] = max(take, notTake);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));
        return helper(n - 1, piles, k, dp);
    }
};