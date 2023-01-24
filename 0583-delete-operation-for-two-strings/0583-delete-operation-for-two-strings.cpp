class Solution {
public:
    // in lcs, abc = a + bc
    // if(c1 == c2) ans = lcs(r1, r2) + 1
    // else ans = max(lcs(c1r1, r2), lcs(r1, c2r2))

    int longestCommonSubsequence(string text1, string text2) {
        int res = 0;
        int n = text1.size(), m = text2.size();
        int dp[n+1][m+1];
        for (int i = 0; i < n+1; i++) dp[i][0] = 0;
        for (int i = 0; i < m+1; i++) dp[0][i] = 0;
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 1; j < m+1; j++)
            {
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1, word2);
        return word1.size() + word2.size() - 2 * lcs;
    }
};