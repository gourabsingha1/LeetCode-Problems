class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up
    int dp[41][41][1661][4];

    int helper(int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& grid, int k, int direction) {
        if(x == grid.size() - 1 && y == grid[0].size() - 1) {
            return 0;
        }
        if(k == -1) {
            return 1661;
        }
        if(dp[x][y][k][direction]) {
            return dp[x][y][k][direction];
        }

        vis[x][y] = 1;
        int res = 1661;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && !vis[dx][dy]){
                res = min(res, 1 + helper(dx, dy, vis, grid, k - grid[dx][dy], i));
            }
        }
        vis[x][y] = 0;
        return dp[x][y][k][direction] = res;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        int res = helper(0, 0, vis, grid, k, 0);
        if(res == 1661) {
            return -1;
        }
        return res;
    }
};