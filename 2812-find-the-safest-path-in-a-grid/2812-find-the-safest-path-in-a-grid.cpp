// find the safeness factor of every 0 cell first
// take the path with shortest safeness factor

class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    int dijkstra(int n, int m, vector<vector<int>>& grid){
        vector<vector<int>> dist(n, vector<int>(m, -1e9));
        dist[0][0] = grid[0][0];
        priority_queue<vector<int>> pq; // dist, row, col
        pq.push({grid[0][0], 0, 0});
        while(pq.size()){
            auto v = pq.top();
            pq.pop();
            int prev = v[0], x = v[1], y = v[2];
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if(dx >= 0 && dy >= 0 && dx < n && dy < m){
                    int safenessFactor = min(prev, grid[dx][dy]);
                    if(dist[dx][dy] < safenessFactor) {
                        pq.push({safenessFactor, dx, dy});
                        dist[dx][dy] = safenessFactor;
                    }
                }
            }
        }
        return dist[n - 1][m - 1] - 1;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        while(q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if(dx >= 0 && dy >= 0 && dx < n && dy < n){
                    if(grid[dx][dy] == 0) {
                        q.push({dx, dy});
                        grid[dx][dy] = grid[x][y] + 1;
                    }
                }
            }
        }
        return dijkstra(grid.size(), grid[0].size(), grid);
    }
};