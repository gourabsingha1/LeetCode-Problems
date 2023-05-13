class Solution {
public:
    // memoization
    int M = 1e9 + 7;
    int helper(int cur, int& low, int& high, int& zero, int& one, vector<int>& dp) {
        if(cur > high) {
            return 0;
        }
        if(dp[cur] != -1) {
            return dp[cur];
        }
        int appendZero = helper(cur + zero, low, high, zero, one, dp);
        int appendOne = helper(cur + one, low, high, zero, one, dp);
        return dp[cur] = (appendOne + appendZero + (low <= cur)) % M;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return helper(0, low, high, zero, one, dp);
    }
};