class Solution {
public:
    int res = 0;
    void dfs(int u, int time, vector<int> adj[], vector<int>& informTime) {
        if(!informTime[u]){
            res = max(res, time);
            return;
        }
        for(auto &v : adj[u]){
            dfs(v, time + informTime[u], adj, informTime);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            if(i != headID){
                int u = i, v = manager[i];
                adj[v].push_back(u);
            }
        }
        dfs(headID, 0, adj, informTime);
        return res;
    }
};