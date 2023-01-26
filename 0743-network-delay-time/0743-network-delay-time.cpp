class Solution {
public:
    int res = 0;
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n + 1];
        for (int i = 0; i < times.size(); i++)
        {
            int u = times[i][0], v = times[i][1], wt = times[i][2];
            adj[u].push_back({v, wt});
        }
        vector<int> path = Dijkstras(k, n + 1, adj);
        for (int i = 1; i < n + 1; i++)
        {
            res = max(res, path[i]);
        }
        if(res == 1e9) res = -1;
        return res;
    }
};