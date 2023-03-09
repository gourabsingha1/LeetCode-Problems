class Solution {
public:
    // memoization
    int helper(int n, string& s, vector<int>& dp) {
        if(n < 0) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int one = 0, two = 0;
        if(s[n] != '0') {
            one = helper(n - 1, s, dp);
        }
        if(n - 1 >= 0 && (s[n - 1] == '1' || s[n - 1] == '2' && s[n] <= '6')) {
            two = helper(n - 2, s, dp);
        }
        return dp[n] = one + two;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return helper(s.size() - 1, s, dp);
    }
};