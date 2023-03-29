class Solution {
public:
    // memoization
    int helper(int n, int j, vector<int>& satisfaction, vector<vector<int>>& dp) {
        if(n < 0) {
            return 0;
        }
        if(dp[n][j] != -1) {
            return dp[n][j];
        }
        int take = satisfaction[n] * j + helper(n - 1, j + 1, satisfaction, dp);
        int notTake = helper(n - 1, j, satisfaction, dp);
        return dp[n][j] = max(take, notTake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.rbegin(), satisfaction.rend());
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return helper(n - 1, 1, satisfaction, dp);
    }
};