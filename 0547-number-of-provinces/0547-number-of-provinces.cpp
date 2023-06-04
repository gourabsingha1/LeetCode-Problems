class Solution {
public:
    void dfs(int u, vector<bool> &vis, vector<int> adj[]){
        vis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(v, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0, n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(isConnected[i][j] && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                res++;
                dfs(i, vis, adj);
            }
        }
        return res;
    }
};