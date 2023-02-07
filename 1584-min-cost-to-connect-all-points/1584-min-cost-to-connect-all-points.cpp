class Solution {
public:
    int prims(int n, vector<vector<int>> adj[]){
        int cost = 0;
        vector<bool> vis(n);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0}); // dist, node
        while(pq.size()){
            int prev = pq.top().first, u = pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            cost += prev;
            for(auto &it : adj[u]){
                int v = it[0], wt = it[1];
                if(!vis[v]){
                    pq.push({wt, v});
                }
            }
        }
        return cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i != j){
                    int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    adj[i].push_back({j, wt});
                }
            }
        }
        return prims(n, adj);
    }
};