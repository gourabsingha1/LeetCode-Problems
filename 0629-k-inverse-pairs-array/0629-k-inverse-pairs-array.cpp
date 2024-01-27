// Tabulation - O(N * N * K), O(K)

class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = 1e9 + 7;
        vector<int> prev(k + 1, 0);
        for (int N = 1; N <= n; N++)
        {
            vector<int> cur(k + 1, 0);
            for (int K = 0; K <= k; K++)
            {
                for (int i = 0; i <= min(K, N - 1); i++)
                {
                    if(K == 0) {
                        cur[K] = 1;
                    }
                    else {
                        cur[K] = (cur[K] + prev[K - i]) % M;
                    }
                }
            }
            prev = cur;
        }
        return prev[k];
    }
};