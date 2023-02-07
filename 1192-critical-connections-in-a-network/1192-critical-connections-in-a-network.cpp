class Solution {
public:
    void dfs(int node, int parent, vector<bool> &vis, vector<int> &tin, vector<int> &low, int timer, vector<int> adj[], vector<vector<int>> &res){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto &it : adj[node]){
            if(it == parent){
                continue;
            }
            if(!vis[it]){
                dfs(it, node, vis, tin, low, timer, adj, res);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){ // Formula
                    res.push_back({node, it});
                }
            }
            else{
                low[node] = min(low[node], tin[it]); // vertex with two or more nodes
            }
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        vector<int> adj[n], tin(n, -1), low(n, -1); // adj, time of insertion, low
        vector<bool> vis(n);
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int timer = 0;
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                dfs(i, -1, vis, tin, low, timer, adj, res);
            }
        }
        return res;
    }
};