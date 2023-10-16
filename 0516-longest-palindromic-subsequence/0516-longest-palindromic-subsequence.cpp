class Solution {
public:
    int helper(int i, int n, string& s, vector<vector<int>>& dp) {
        if(i > n) {
            return 0;
        }
        if(i == n) {
            return 1;
        }
        if(dp[i][n] != -1) {
            return dp[i][n];
        }

        int res = 0;
        if(s[i] == s[n]) {
            res = 2 + helper(i + 1, n - 1, s, dp);
        }
        else {
            int first = helper(i + 1, n, s, dp);
            int second = helper(i, n - 1, s, dp);
            res = max(first, second);
        }
        return dp[i][n] = res;
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(0, n - 1, s, dp);
    }
};