class Solution {
public:
    vector<vector<int>> createGraph(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    void dfs(vector<bool> &vis, int i, vector<vector<int>> &adj){
        vis[i] = 1;
        for(auto &it : adj[i]){
            if(!vis[it]){
                dfs(vis, it, adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int res = -1;
        if(n > connections.size() + 1){
            return -1;
        }
        vector<vector<int>> adj = createGraph(n, connections);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                dfs(vis, i, adj);
                res++;
            }
        }
        return res;
    }
};