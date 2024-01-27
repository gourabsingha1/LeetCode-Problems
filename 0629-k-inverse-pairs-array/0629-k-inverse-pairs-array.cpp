// Tabulation + Sliding window - O(N * K), O(K)

class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = 1e9 + 7;
        vector<int> prev(k + 1, 0);
        prev[0] = 1;
        for (int N = 1; N <= n; N++)
        {
            vector<int> cur(k + 1, 0);
            long total = 0;
            for (int K = 0; K <= k; K++)
            {
                total = (total + prev[K] + M) % M;
                if(K >= N) {
                    total = (total - prev[K - N] + M) % M;
                }
                cur[K] = total;
            }
            prev = cur;
        }
        return prev[k];
    }
};