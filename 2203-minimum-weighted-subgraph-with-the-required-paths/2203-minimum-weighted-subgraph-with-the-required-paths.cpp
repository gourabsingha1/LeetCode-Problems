class Solution {
public:
    vector<long long> dijkstra(int src, int n, vector<vector<int>> adj[]){
        vector<long long> dist(n, 1e18);
        priority_queue <pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while(pq.size()){
            auto [prev, u] = pq.top();
            pq.pop();
            if (prev > dist[u]) continue;
            for(auto &it : adj[u]){
                int v = it[0], wt = it[1];
                if(dist[v] > prev + wt){
                    dist[v] = prev + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        long long res = 1e18;
        vector<vector<int>> adj[n], revAdj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            revAdj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<long long> src1ToX = dijkstra(src1, n, adj);
        vector<long long> src2ToX = dijkstra(src2, n, adj);
        vector<long long> xToDest = dijkstra(dest, n, revAdj);
        for (int i = 0; i < n; i++)
        {
            if(src1ToX[i] == 1e18 || src1ToX[i] == 1e18 || src1ToX[i] == 1e18) continue;
            res = min(res, src1ToX[i] + src2ToX[i] + xToDest[i]);
        }
        if(res == 1e18) res = -1;
        return res;
    }
};