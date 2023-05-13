class Solution {
public:
    // tabulation
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        int M = 1e9 + 7;
        for (int cur = high; cur >= 0; cur--)
        {
            int appendZero = 0;
            if(cur + zero <= high) {
                appendZero = dp[cur + zero];
            }
            int appendOne = 0;
            if(cur + one <= high) {
                appendOne = dp[cur + one];
            }
            dp[cur] = (appendOne + appendZero + (low <= cur)) % M;
        }
        return dp[0];
    }
};