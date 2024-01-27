// Tabulation - O(N * N * K), O(N * K)

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {}, M = 1e9 + 7;
        for (int N = 1; N <= n; N++)
        {
            for (int K = 0; K <= k; K++)
            {
                for (int i = 0; i <= min(K, N - 1); i++)
                {
                    if(K == 0) {
                        dp[N][K] = 1;
                    }
                    else {
                        dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % M;
                    }
                }
            }
        }
        return dp[n][k];
    }
};