// memoization
class Solution {
public:
    bool helper(int n, int m, string& s, string& p, vector<vector<int>>& dp) {
        if(n < 0 || m < 0) {
            if(m >= 0) {
                for (int i = 0; i <= m; i++)
                {
                    if(p[i] != '*') return 0;
                }
                return 1;
            }
            return n < 0 && m < 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        bool res = 0;
        if(s[n] == p[m] || p[m] == '?') {
            res = helper(n - 1, m - 1, s, p, dp);
        }
        else if(p[m] == '*') {
            for (int i = n; i >= -1; i--)
            {
                res |= helper(i, m - 1, s, p, dp);
            }
        }
        return dp[n][m] = res;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n - 1, m - 1, s, p, dp);
    }
};