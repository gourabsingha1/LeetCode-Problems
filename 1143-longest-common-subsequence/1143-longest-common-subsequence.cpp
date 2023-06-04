// in lcs, abc = a + bc = c + r
// if(c1 == c2) ans = lcs(r1, r2) + 1
// else ans = max(lcs(c1r1, r2), lcs(r1, c2r2))

// memoization
class Solution {
public:
    int helper(int n, int m, string& text1, string& text2, vector<vector<int>>& dp) {
        if(n < 0 || m < 0) {
            return 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        int res = 0;
        if(text1[n] == text2[m]) {
            res = 1 + helper(n - 1, m - 1, text1, text2, dp);
        }
        else {
            int first = helper(n - 1, m, text1, text2, dp);
            int second = helper(n, m - 1, text1, text2, dp);
            res = max(first, second);
        }
        return dp[n][m] = res;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n - 1, m - 1, text1, text2, dp);
    }
};