class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int dijkstra(vector<vector<int>>& grid){
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m));
        priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;
        vis[0][0] = 0;
        pq.push({0, 0, 0}); // dist, node
        while(pq.size()) {
            int time = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
            pq.pop();
            if(x == n - 1 && y == m - 1) {
                return time;
            }
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if(dx >= 0 && dy >= 0 && dx < n && dy < m && !vis[dx][dy]){
                    bool wait = (grid[dx][dy] - time) % 2 == 0;
                    pq.push({max(grid[dx][dy] + wait, time + 1), dx, dy});
                    vis[dx][dy] = 1;
                }
            }
        }
        return -1;
    }
    int minimumTime(vector<vector<int>>& grid) {
        return dijkstra(grid);
    }
};