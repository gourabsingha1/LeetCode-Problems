class Solution {
public:
    int res = -1;
    bool vis[100000], dfsVis[100000];
    int soFar[100000] = {};
    void dfs(int curr, int u, vector<int> adj[]){
        vis[u] = 1;
        dfsVis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                soFar[v] = curr;
                dfs(curr + 1, v, adj);
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
                dfs(curr, i, adj);
            }
        }
        return res;
    }
};