// we can only remove stones if they are connected
// stones lying on same row forms a graph. similarly for columms
// treat indices of stones as nodes of a graph
// build the graph then return n - number of island
// because last node of each island cannot be removed

class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    void dfs(vector<bool>& vis, int u, vector<int> adj[]){
        vis[u] = 1;
        for(auto& v : adj[u]) {
            if(vis[v]) continue;
            dfs(vis, v, adj);
        }
    }

    int numIslands(int n, vector<int> adj[]) {
        int res = 0;
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                dfs(vis, i, adj);
                res++;
            }
        }
        return res;
    }

    int removeStones(vector<vector<int>>& stones) {
        int res = 0, n = stones.size();
        unordered_map<int, vector<int>> rows, cols;
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            int x = stones[i][0], y = stones[i][1];
            rows[x].push_back(i);
            cols[y].push_back(i);
        }
        for(auto& [x, nodes] : rows) {
            for (int i = 1; i < nodes.size(); i++)
            {
                int u = nodes[i - 1], v = nodes[i];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        for(auto& [x, nodes] : cols) {
            for (int i = 1; i < nodes.size(); i++)
            {
                int u = nodes[i - 1], v = nodes[i];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        return n - numIslands(n, adj);
    }
};