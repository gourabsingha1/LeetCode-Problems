class Solution {
public:
    int helper(int n, int m, string& s, string& t, vector<vector<int>>& dp) {
        if(n < 0 || m < 0) {
            return m < 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        int take = 0;
        if(s[n] == t[m]) {
            take = helper(n - 1, m - 1, s, t, dp);
        }
        int notTake = helper(n - 1, m, s, t, dp);
        return dp[n][m] = take + notTake;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n - 1, m - 1, s, t, dp);
    }
};