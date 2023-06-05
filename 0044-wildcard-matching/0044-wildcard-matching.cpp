// memoization
class Solution {
public:
    bool helper(int n, int m, string& s, string& p, vector<vector<int>>& dp) {
        if(m == 0) {
            return n == 0;
        }
        if(n == 0) {
            for (int i = 0; i < m; i++)
            {
                if(p[i] != '*') return 0;
            }
            return 1;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        bool res = 0;
        if(s[n - 1] == p[m - 1] || p[m - 1] == '?') {
            res = helper(n - 1, m - 1, s, p, dp);
        }
        else if(p[m - 1] == '*') {
            for (int i = n + 1; i >= 1; i--)
            {
                res |= helper(i - 1, m - 1, s, p, dp);
            }
        }
        return dp[n][m] = res;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return helper(n, m, s, p, dp);
    }
};