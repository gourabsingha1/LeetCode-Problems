// two person collects cherries from top left cell
// if they stand at the same cell, add the cell value only once

class Solution {
public:
    // (l, l), (l, d), (d, l), (d, d)
    vector<vector<int>> dir = {{1, 0, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 0, 1}};

    int helper(int r1, int c1, int r2, int c2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(r1 == n - 1 && c1 == n - 1 && r2 == n - 1 && c2 == n - 1) {
            return grid[r1][c1];
        }
        if(dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }

        int res = grid[r1][c1];
        if(r1 != r2 || c1 != c2) {
            res += grid[r2][c2];
        }
        
        int temp = -1e9;
        for (int i = 0; i < 4; i++)
        {
            int dr1 = r1 + dir[i][0], dc1 = c1 + dir[i][1], dr2 = r2 + dir[i][2], dc2 = c2 + dir[i][3];
            if(dr1 < n && dc1 < n && dr2 < n && dc2 < n && grid[dr1][dc1] != -1 && grid[dr2][dc2] != -1) {
                temp = max(temp, helper(dr1, dc1, dr2, dc2, n, grid, dp));
            }
        }
        return dp[r1][c1][r2] = res + temp;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int>(n, -1)));
        return max(0, helper(0, 0, 0, 0, n, grid, dp));
    }
};