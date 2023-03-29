class Solution {
public:
    // memoization
    int helper(int i, int j, vector<int>& satisfaction, vector<vector<int>>& dp) {
        if(i == satisfaction.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int take = satisfaction[i] * j + helper(i + 1, j + 1, satisfaction, dp);
        int notTake = helper(i + 1, j, satisfaction, dp);
        return dp[i][j] = max(take, notTake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(satisfaction.size(), vector<int> (satisfaction.size() + 1, -1));
        return helper(0, 1, satisfaction, dp);
    }
};