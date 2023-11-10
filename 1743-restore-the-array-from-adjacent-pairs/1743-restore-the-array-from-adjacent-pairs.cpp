class Solution {
public:
    void dfs(int u, int parent, unordered_map<int, vector<int>>& adj, vector<int>& res) {
        res.push_back(u);
        for(auto& v : adj[u]) {
            if(v != parent) {
                dfs(v, u, adj, res);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> res;
        int n = adjacentPairs.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++)
        {
            int u = adjacentPairs[i][0], v = adjacentPairs[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int src;
        for(auto& [u, v] : adj) {
            if(v.size() == 1) {
                src = u;
                break;
            }
        }
        
        dfs(src, -1, adj, res);
        return res;
    }
};