class Solution {
public:
    bool helper(int alice, int bob, int i, int n, vector<int>& piles, vector<vector<int>>& dp) {
        if(i >= n) {
            return alice > bob;
        }
        if(dp[i][n] != -1) {
            return dp[i][n];
        }
        bool res = 0;
        // beginning
        res |= helper(alice + piles[i], bob + piles[i + 1], i + 2, n, piles, dp) || helper(alice + piles[i], bob + piles[n], i + 1, n - 1, piles, dp);
        // ending
        res |= helper(alice + piles[n], bob + piles[n - 1], i, n - 2, piles, dp) || helper(alice + piles[n], bob + piles[i], i + 1, n - 1, piles, dp);
        return dp[i][n] = res;
    }
    bool stoneGame(vector<int>& piles) {
        int sum = accumulate(piles.begin(), piles.end(), 0), n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(0, 0, 0, piles.size() - 1, piles, dp);
    }
};