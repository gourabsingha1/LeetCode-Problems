// in lcs, abc = a + bc = c + r
// if(c1 == c2) ans = lcs(r1, r2) + 1
// else ans = max(lcs(c1r1, r2), lcs(r1, c2r2))

// tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int res = 0;
                if(text1[i - 1] == text2[j - 1]) {
                    res = 1 + dp[i - 1][j - 1];
                }
                else {
                    int first = dp[i - 1][j];
                    int second = dp[i][j - 1];
                    res = max(first, second);
                }
                dp[i][j] = res;
            }
        }
        return dp[n][m];
    }
};