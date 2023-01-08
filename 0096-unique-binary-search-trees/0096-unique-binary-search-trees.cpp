class Solution {
public:
    int catalanNumber(int n){
        int dp[n + 1];
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j <= i; j++)
            {
                int left = j - 1, right = i - j;
                dp[i] += dp[left] * dp[right];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        return catalanNumber(n);
    }
};