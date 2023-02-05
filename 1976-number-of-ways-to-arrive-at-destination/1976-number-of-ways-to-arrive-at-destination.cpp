#define ll long long
class Solution {
public:
    int M = 1e9 + 7;
    int dijkstras(int src, int n, vector<vector<int>> adj[]){
        vector<ll> dist(n, 1e18), ways(n);
        priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        dist[src] = 0;
        ways[src] = 1;
        pq.push({0, src}); // dist, node
        while(pq.size()){
            auto [prev, i] = pq.top();
            pq.pop();
            for(auto &it : adj[i]){
                ll j = it[0], wt = it[1];
                if(dist[j] > prev + wt){
                    dist[j] = prev + wt;
                    pq.push({dist[j], j});
                    ways[j] = ways[i];
                }
                else if(dist[j] == prev + wt){
                    ways[j] = (ways[j] + ways[i]) % M;
                }
            }
        }
        return ways[n - 1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj[n];
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0], v = roads[i][1], wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        return dijkstras(0, n, adj);
    }
};