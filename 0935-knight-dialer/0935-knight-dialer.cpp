// brute force

class Solution {
public:
    int dp[5001][10], M = 1e9 + 7;

    int helper(int n, int u, vector<int> adj[]) {
        if(n == 0) {
            return 1;
        }
        if(dp[n][u] != -1) {
            return dp[n][u];
        }

        int res = 0;
        for(auto& v : adj[u]) {
            res = (res + helper(n - 1, v, adj)) % M;
        }
        return dp[n][u] = res;
    }

    int knightDialer(int n) {
        vector<int> adj[10] = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        int res = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 10; i++)
        {
            res = (res + helper(n - 1, i, adj)) % M;
        }
        return res;
    }
};