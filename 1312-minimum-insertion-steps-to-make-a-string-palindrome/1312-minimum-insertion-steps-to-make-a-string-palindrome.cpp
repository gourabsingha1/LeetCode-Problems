class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int res = 0, n = text1.size(), m = text2.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++) dp[i][0] = 0;
        for (int i = 0; i < m + 1; i++) dp[0][i] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
    int minInsertions(string s) {
        string p = s;
        reverse(p.begin(), p.end());
        return s.size() - longestCommonSubsequence(s, p);
    }
};