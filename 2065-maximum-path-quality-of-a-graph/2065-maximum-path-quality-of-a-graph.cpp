class Solution {
public: 
    int res = 0;

    void helper(int cur, int u, vector<int>& vis, vector<int>& values, vector<vector<int>> adj[], int maxTime) {
        if(u == 0) {
            res = max(res, cur);
        }

        vis[u]++;
        for(auto& it : adj[u]) {
            int v = it[0], time = it[1];
            if(maxTime - time >= 0) {
                int x = 0;
                if(!vis[v]) {
                    x = values[v];
                }
                helper(cur + x, v, vis, values, adj, maxTime - time);
            }
        }
        vis[u]--;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<int>> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], time = edges[i][2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        vector<int> vis(n, 0);
        helper(values[0], 0, vis, values, adj, maxTime);
        return res;
    }
};