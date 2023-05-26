// Correct Solution
class Solution {
public:
    int helper(int i, int n, bool turn, vector<int>& piles, vector<vector<int>>& dp) {
        if(i >= n) {
            return 0;
        }
        if(dp[i][n] != -1) {
            return dp[i][n];
        }
        int left = piles[i] + helper(i + 1, n, !turn, piles, dp), right = piles[n] + helper(i, n - 1, !turn, piles, dp);
        if(!turn) {
            left -= piles[i], right -= piles[n];
        }
        return dp[i][n] = max(left, right);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(0, n - 1, 1, piles, dp) > sum / 2;
    }
};