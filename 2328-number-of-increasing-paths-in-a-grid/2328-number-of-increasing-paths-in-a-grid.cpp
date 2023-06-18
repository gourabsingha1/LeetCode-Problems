class Solution {
public:
    int M = 1e9 + 7;
    vector<int> dir = {0, 1, 0, -1, 0};
    int helper(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(dp[x][y] != -1) {
            return dp[x][y];
        }
        int n = grid.size(), m = grid[0].size(), res = 0;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && grid[x][y] < grid[dx][dy]) {
                res = (res + 1 + helper(dx, dy, grid, dp)) % M;
            }
        }
        return dp[x][y] = res;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = n * m;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res = (res + helper(i, j, grid, dp)) % M;
            }
        }
        return res;
    }
};