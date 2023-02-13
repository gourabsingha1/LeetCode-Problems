class Solution {
public:
    double dijkstras(int src, int n, vector<vector<pair<int, double>>> &adj, int end){
        vector<double> dist(n, 0);
        priority_queue <pair<double, int>> pq;
        dist[src] = 0;
        pq.push({1, src}); // dist, node
        while(pq.size()){
            auto [prev, u] = pq.top();
            pq.pop();
            for(auto &it : adj[u]){
                auto [v, wt] = it;
                if(dist[v] < prev * wt){
                    dist[v] = prev * wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[end];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        return dijkstras(start, n, adj, end);
    }
};