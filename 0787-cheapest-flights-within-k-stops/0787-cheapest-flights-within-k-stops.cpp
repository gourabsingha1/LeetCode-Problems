class Solution {
public:
    int bellmanFord(int src, int dst, int k, int n, vector<vector<int>> &edges){
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        for (int i = 0; i < k + 1; i++)
        {
            vector<int> temp(dist);
            for(auto &it : edges){
                int u = it[0], v = it[1], wt = it[2];
                temp[v] = min(temp[v], dist[u] + wt);
            }
            dist = temp;
        }
        return dist[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int res = bellmanFord(src, dst, k, n, flights);
        if(res == 1e9) return -1;
        return res;
    }
};