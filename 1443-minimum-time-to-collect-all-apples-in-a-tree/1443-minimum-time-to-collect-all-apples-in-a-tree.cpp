class Solution {
public:
    int dfs(int currInd, int parent, vector<vector<int>> &adj, vector<bool>& hasApple){
        int res = 0;
        for(auto &it : adj[currInd]){
            if(it == parent) continue;
            int childTime = dfs(it, currInd, adj, hasApple);
            if(childTime > 0 || hasApple[it]){
                res += childTime + 2;
            }
        }
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0, -1, adj, hasApple);
    }
};