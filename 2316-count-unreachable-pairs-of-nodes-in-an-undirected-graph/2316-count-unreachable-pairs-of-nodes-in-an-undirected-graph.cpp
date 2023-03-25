class Solution {
public:
    void dfs(int& vertices, int u, vector<bool>& vis, vector<int> adj[]) {
        vis[u] = 1;
        vertices++;
        for(auto& v : adj[u]) {
            if(!vis[v]) {
                dfs(vertices, v, vis, adj);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long res = 0;
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> nums;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]) {
                int vertices = 0;
                dfs(vertices, i, vis, adj);
                nums.push_back(vertices);
            }
        }
        int sum = n;
        for (int i = 0; i < nums.size(); i++)
        {
            sum -= nums[i];
            res += 1LL * nums[i] * sum;
        }
        return res;
    }
};