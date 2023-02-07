class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), connected = n, cost = 0;
        vector<bool> vis(n);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0}); // dist, node
        while(connected--){
            int prev = pq.top().first, u = pq.top().second;
            vis[u] = 1;
            while(pq.size() && vis[pq.top().second]){
                pq.pop();
            }
            cost += prev;
            for (int i = 0; i < n; i++)
            {
                int v = i, wt = abs(points[i][0] - points[u][0]) + abs(points[i][1] - points[u][1]);
                if(!vis[v]){
                    pq.push({wt, v});
                }
            }
        }
        return cost;
    }
};