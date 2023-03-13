class Solution {
public:
    // tabulation
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else {
                    int take = 0, sum = 0;
                    for (int l = 0; l < piles[i - 1].size() && j - l - 1 >= 0; l++)
                    {
                        sum += piles[i - 1][l]; // prefix sum
                        take = max(take, sum + dp[i - 1][j - l - 1]);
                    }
                    int notTake = dp[i - 1][j];
                    dp[i][j] = max(take, notTake);
                }
            }
        }
        return dp[n][k];
    }
};