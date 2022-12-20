class Solution {
public:
    bool dfsOfGraph(int V, vector<vector<int>> adj){
        vector<int> vis(V, 0);
        vis[0] = 1;
        for(int i = 0; i < V; i++){
            if(vis[i]){
                dfs(i, vis, adj);
            }
        }
        int c = 0;
        for(int &b : vis){
            if(b) c++;
        }
        return c == V;
    }
    void dfs(int node, vector<int> &vis, vector<vector<int>> adj){
        vis[node] = 1;
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        return dfsOfGraph(rooms.size(), rooms);
    }
};