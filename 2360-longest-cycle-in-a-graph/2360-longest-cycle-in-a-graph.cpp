class Solution {
public:
    int res = -1;
    int soFar[100000] = {};
    void dfs(int curr, int u, vector<bool> &vis, vector<bool> &dfsVis, vector<int> adj[]){
        vis[u] = 1;
        dfsVis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                soFar[v] = curr;
                dfs(curr + 1, v, vis, dfsVis, adj);
            }
            else if(dfsVis[v]){
                res = max(res, curr - soFar[v]);
            }
        }
        dfsVis[u] = 0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        vector<bool> vis(n), dfsVis(n);
        for (int i = 0; i < n; i++)
        {
            if(edges[i] >= 0){
                adj[i].push_back(edges[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                int curr = 1;
                dfs(curr, i, vis, dfsVis, adj);
            }
        }
        return res;
    }
};