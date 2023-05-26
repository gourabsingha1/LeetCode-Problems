class Solution {
public:
    int helper(int ind, int M, bool alice, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if(ind == piles.size()) {
            return 0;
        }
        if(dp[ind][M][alice] != -1) {
            return dp[ind][M][alice];
        }
        int res = 0, sum = 0;
        if(!alice) res = INT_MAX;
        for (int X = 1; ind + X - 1 < piles.size() && X <= 2 * M; X++)
        {
            sum += piles[ind + X - 1];
            if(alice) {
                res = max(res, sum + helper(ind + X, max(M, X), !alice, piles, dp));
            }
            else {
                res = min(res, helper(ind + X, max(M, X), !alice, piles, dp)); // the helper function returns alice's score and we dont add her score to bob's. thats why we dont add the sum
            }
        }
        return dp[ind][M][alice] = res;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(n == 1) return piles[0];
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));
        return helper(0, 1, 1, piles, dp);
    }
};