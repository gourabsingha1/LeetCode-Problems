class Solution {
public:
    int M = 1e9 + 7;
    vector<int> dir = {1, 0, 1}; // right, down

    int helper(int sumMod, int x, int y, int& n, int& m, vector<vector<int>>& grid, int& k, vector<vector<vector<int>>>& dp) {
        if(x == n - 1 && y == m - 1) {
            return sumMod == 0;
        }
        if(dp[x][y][sumMod] != -1) {
            return dp[x][y][sumMod];
        }

        int res = 0;
        for (int i = 0; i < 2; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < n && dy < m){
                res = (res + helper((sumMod + grid[dx][dy]) % k, dx, dy, n, m, grid, k, dp)) % M;
            }
        }
        return dp[x][y][sumMod] = res;
    }
     
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k, -1)));
        return helper(grid[0][0] % k, 0, 0, n, m, grid, k, dp);
    }
};