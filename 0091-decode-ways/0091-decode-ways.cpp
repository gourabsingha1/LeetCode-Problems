class Solution {
public:
    // tabulation
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        dp[0] = s[0] != '0';
        for (int i = 1; i < n; i++)
        {
            int one = 0, two = 0;
            if(s[i] != '0') {
                one = dp[i - 1];
            }
            if(i - 1 >= 0 && (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')) {
                if(i - 1 == 0) {
                    two = dp[i - 1];
                }
                else {
                    two = dp[i - 2];
                }
            }
            dp[i] = one + two;
        }
        return dp[n - 1];
    }
};