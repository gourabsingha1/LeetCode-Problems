class Solution {
public:
    int helper(int n, int x, int y, vector<int>& stones, vector<vector<int>>& dp) {
        int diff = abs(x - y);
        if(n < 0) {
            return diff;
        }
        if(dp[n][diff] != -1) {
            return dp[n][diff];
        }

        int newX = helper(n - 1, x + stones[n], y, stones, dp);
        int newY = helper(n - 1, x, y + stones[n], stones, dp);
        return dp[n][diff] = min(newX, newY);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), m = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n - 1, 0, 0, stones, dp);
    }
};