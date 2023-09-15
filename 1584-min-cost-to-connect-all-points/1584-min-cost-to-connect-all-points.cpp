class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), cost = 0;
        vector<bool> vis(n);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0}); // dist, node
        while(n--){
            auto [prev, j] = pq.top();
            vis[j] = 1;
            while(pq.size() && vis[pq.top().second]){
                pq.pop();
            }
            cost += prev;
            for (int i = 0; i < points.size(); i++)
            {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                if(!vis[i]){
                    pq.push({wt, i});
                }
            }
        }
        return cost;
    }
};