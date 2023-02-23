class Solution {
public:
    int res = INT_MAX;
    void dfs(int u, vector<bool> &vis, vector<vector<int>> adj[]){
        vis[u] = 1;
        for(auto &it : adj[u]){
            int v = it[0], wt = it[1];
            res = min(res, wt);
            if(!vis[v]){
                dfs(v, vis, adj);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj[n + 1];
        vector<bool> vis(n + 1);
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0], v = roads[i][1], wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        dfs(1, vis, adj);
        return res;
    }
};