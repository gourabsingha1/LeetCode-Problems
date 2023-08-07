class Solution {
public:
    int dfs(int u, int dst, int k, vector<pair<int, int>> adj[], vector<vector<int>>& dp){
        if(u == dst){
            return 0;
        }
        if(k < 0) {
            return 1e9;
        }
        if(dp[u][k] != -1) {
            return dp[u][k];
        }
        
        int res = 1e9;
        for(auto &[v, price] : adj[u]){
            res = min(res, price + dfs(v, dst, k - 1, adj, dp));
        }
        return dp[u][k] = res;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0], v = flights[i][1], cost = flights[i][2];
            adj[u].push_back({v, cost});
        }
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));
        int res = dfs(src, dst, k, adj, dp);
        if(res >= 1e9) return -1;
        return res;
    }
};