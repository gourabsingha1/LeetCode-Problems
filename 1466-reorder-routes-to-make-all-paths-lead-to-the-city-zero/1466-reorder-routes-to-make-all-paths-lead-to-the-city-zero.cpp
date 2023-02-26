class Solution {
public:
    int res = 0;
    map<pair<int, int>, bool> m;
    void dfs(int u, vector<bool>& vis, vector<int> adj[]){
        vis[u] = 1;
        for (auto &v : adj[u]) {
            if(!vis[v]){
                res += m[{u, v}];
                dfs(v, vis, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (int i = 0; i < n - 1; i++)
        {
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            m[{u, v}] = 1;
        }
        vector<bool> vis(n);
        dfs(0, vis, adj);
        return res;
    }
};