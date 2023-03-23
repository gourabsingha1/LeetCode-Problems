class Solution {
public:
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
        vector<vector<int>> adj(n);
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
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