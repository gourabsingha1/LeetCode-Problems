class Solution {
public:
    int helper(int i, int n, int seen, vector<vector<int>>& dp){
        if(i > n){
            return 1;
        }
        if(dp[i][seen] != -1) {
            return dp[i][seen];
        }
        
        int res = 0;
        for (int j = 1; j <= n; j++)
        {
            int bit = 1 << (j - 1);
            if(seen & bit) continue;
            if(i % j == 0 || j % i == 0) {
                res = res + helper(i + 1, n, seen | bit, dp);
            }
        }
        return dp[i][seen] = res;
    }

    int countArrangement(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (1 << n, -1));
        return helper(1, n, 0, dp);
    }
};