// for mat[i][j], store its val + min of top, topAdjLeft & topAdjRight

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int mn = 1e9;
                for (int k = 0; k < m; k++) {
                    if(j != k) {
                        mn = min(mn, grid[i - 1][k]);
                    }
                }
                grid[i][j] += mn;
            }
        }
        return *min_element(grid[n - 1].begin(), grid[n - 1].end());
    }
};