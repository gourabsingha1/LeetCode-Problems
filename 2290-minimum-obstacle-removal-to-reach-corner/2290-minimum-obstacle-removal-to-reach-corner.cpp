class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    int dijkstra(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size(), res = 1e9;
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;
        dist[0][0] = 0;
        pq.push({0, 0, 0}); // dist, x, y
        while(pq.size()){
            int prev = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
            pq.pop();
            if (prev > dist[x][y]) continue;
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size()){
                    int wt = grid[dx][dy];
                    if(dist[dx][dy] > prev + wt){
                        dist[dx][dy] = prev + wt;
                        pq.push({dist[dx][dy], dx, dy});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        return dijkstra(grid);
    }
};