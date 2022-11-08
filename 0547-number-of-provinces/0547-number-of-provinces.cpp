class Solution {
public:
    int res = 0;
    void dfsOfGraph(int V, vector<int> adj[]){
        vector<bool> vis(V+1, 0);
        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                res++;
                dfs(i, vis, adj);
            }
        }
        return;
    }
    void dfs(int node, vector<bool> &vis, vector<int> adj[]){
        vis[node] = 1;
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V+1];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if(isConnected[i][j] && i!=j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        dfsOfGraph(V, adj);
        return res;
    }
};