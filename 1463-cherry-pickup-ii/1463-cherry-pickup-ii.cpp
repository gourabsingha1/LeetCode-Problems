// same as cherry pickup I. except they start from different positions
// rows of both robots will be the same

class Solution {
public:
    // (left, left), (left, down), (left, right), (down, left), (down, down), (down, right), (right, left), (right, down), (right, right)
    vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int helper(int r1, int c1, int r2, int c2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(r1 == n - 1) {
            if(c1 == c2) {
                return grid[r1][c1];
            }
            return grid[n - 1][c1] + grid[n - 1][c2];
        }
        if(dp[r1][c1][c2] != -1) {
            return dp[r1][c1][c2];
        }

        int res = grid[r1][c1];
        if(c1 != c2) {
            res += grid[r2][c2];
        }
        
        int temp = -1e9;
        for (int i = 0; i < 9; i++)
        {
            int dr1 = r1 + 1, dc1 = c1 + dir[i][0], dr2 = r2 + 1, dc2 = c2 + dir[i][1];
            if(dr1 < n && dc1 >= 0 && dc1 < m && dr2 < n && dc2 >= 0 && dc2 < m) {
                temp = max(temp, helper(dr1, dc1, dr2, dc2, n, m, grid, dp));
            }
        }
        return dp[r1][c1][c2] = res + temp;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m, -1)));
        return max(0, helper(0, 0, 0, m - 1, n, m, grid, dp));
    }
};