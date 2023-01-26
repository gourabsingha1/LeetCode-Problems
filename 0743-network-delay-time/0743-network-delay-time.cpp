class Solution {
public:
    vector<int> bellmanFord(int src, int n, vector<vector<int>> &edges){
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            vector<int> temp(dist);
            for(auto &it : edges){
                int u = it[0], v = it[1], wt = it[2];
                dist[v] = min(dist[v], dist[u] + wt);
            }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int res = 0;
        vector<int> path = bellmanFord(k, n + 1, times);
        for (int i = 1; i < n + 1; i++)
        {
            res = max(res, path[i]);
        }
        if(res == 1e9) res = -1;
        return res;
    }
};