class Solution {
public:
    void dfs(int u, vector<bool> &vis, vector<vector<int>>& adj){
        vis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(v, vis, adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        vis[0] = 1;
        for(int i = 0; i < n; i++){
            if(vis[i]){
                dfs(i, vis, rooms);
            }
        }
        for(auto x : vis){
            if(!x) return 0;
        }
        return 1;
    }
};
