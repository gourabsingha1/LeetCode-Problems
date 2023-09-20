class Solution {
public:
    vector<int> Dijkstras(int src, int n, vector<pair<int,int>> adj[]){
        vector<int> dist(n, 1e9);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while(pq.size()){
            auto [prev, u] = pq.top();
            pq.pop();
            for(auto &[v, cur] : adj[u]){
                if(dist[v] > prev + cur){
                    dist[v] = prev + cur;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int res = 0, currMin = INT_MAX;
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        for (int i = 0; i < n; i++)
        {
            int steps = 0;
            vector<int> dist = Dijkstras(i, n, adj);
            for(auto& d : dist){
                if(d <= distanceThreshold){
                    steps++;
                }
            }
            if(steps <= currMin){
                currMin = steps;
                res = i;
            }
        }
        return res;
    }
};