class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    int bfs(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>> (m, vector<bool> (k + 1, 0)));
        q.push({0, 0, k, 0}); // x, y, k, cur
        vis[0][0][k] = 1;
        while(q.size()) {
            int x = q.front()[0], y = q.front()[1], z = q.front()[2], cur = q.front()[3];
            q.pop();
            if(x == n - 1 && y == m - 1) {
                return cur;
            }

            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && z - grid[dx][dy] >= 0 && !vis[dx][dy][z - grid[dx][dy]]){
                    int dz = z - grid[dx][dy];
                    q.push({dx, dy, dz, cur + 1});
                    vis[dx][dy][dz] = 1;
                }
            }
        }
        return -1;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        return bfs(grid, k);
    }
};