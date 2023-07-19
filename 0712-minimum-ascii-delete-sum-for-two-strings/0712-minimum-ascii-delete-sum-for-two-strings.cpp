class Solution {
public:
    int helper(int n, int m, string& s1, string& s2, vector<vector<int>>& dp) {
        if(n < 0) {
            int sum = 0;
            while(m >= 0) {
                sum += s2[m--];
            }
            return sum;
        }
        else if(m < 0) {
            int sum = 0;
            while(n >= 0) {
                sum += s1[n--];
            }
            return sum;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        int res = INT_MAX;
        if(s1[n] == s2[m]) {
            res = helper(n - 1, m - 1, s1, s2, dp);
        }
        else {
            int first = s1[n] + helper(n - 1, m, s1, s2, dp);
            int second = s2[m] + helper(n, m - 1, s1, s2, dp);
            res = min(first, second);
        }
        return dp[n][m] = res;
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n - 1, m - 1, s1, s2, dp);
    }
};