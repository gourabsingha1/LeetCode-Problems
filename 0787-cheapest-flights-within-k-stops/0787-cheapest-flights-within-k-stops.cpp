class Solution {
public:
    int res = INT_MAX;
    unordered_map<string, int> m;
    void dfs(int i, int curr, int dst, int k, vector<pair<int, int>> adj[]){
        if(i == dst){
            res = min(res, curr);
            return;
        }
        if(k < 0 || curr >= res) return;
        string key = to_string(i) + "*" + to_string(curr) + "*" + to_string(k);
        if(m[key]) return;
        m[key] = 1;
        for(auto &it : adj[i]){
            int j = it.first, cost = it.second;
            dfs(j, curr + cost, dst, k - 1, adj);
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0], v = flights[i][1], cost = flights[i][2];
            adj[u].push_back({v, cost});
        }
        dfs(src, 0, dst, k, adj);
        if(res == INT_MAX) return -1;
        return res;
    }
};