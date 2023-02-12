class Solution {
public:
    long long res = 0;
    long long dfs(int u, int prev, vector<vector<int>>& adj, int &seats){
        long long temp = 1;
        for(auto &v : adj[u]){
            if(v == prev) continue;
            temp += dfs(v, u, adj, seats);
            // cout<<v<<" "<<temp<<" "<<res<<endl;
        }
        if(u){
            res += (temp + seats - 1) / seats;
        }
        return temp;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n; i++)
        {
            int u = roads[i][0], v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, 0, adj, seats);
        return res;
    }
};