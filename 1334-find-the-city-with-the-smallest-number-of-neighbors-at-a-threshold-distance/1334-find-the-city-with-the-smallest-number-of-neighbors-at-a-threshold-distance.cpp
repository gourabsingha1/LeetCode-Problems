class Solution {
public:
    vector<int> Dijkstras(int src, int n, vector<pair<int,int>> adj[]){
        vector<int> distTo(n, 1e9);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // ascending order
        distTo[src] = 0;
        pq.push({0, src});
        while(pq.size()){
            int dist = pq.top().first, prev = pq.top().second;
            pq.pop();
            for(auto &it : adj[prev]){
                int next = it.first;
                int nextDist = it.second;
                if(distTo[next] > dist + nextDist){
                    distTo[next] = dist + nextDist;
                    pq.push({distTo[next], next});
                }
            }
        }
        return distTo;
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