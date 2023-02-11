class Solution {
public:
    int maxDistance(vector<vector<int>>& grid){
        int res = 0, one = 0, m = grid.size(), n = grid[0].size(), inf = m + n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    one++;
                    continue;
                }
                int top = inf, left = inf;
                if (i - 1 >= 0){
                    top = grid[i - 1][j];
                }
                if (j - 1 >= 0){
                    left = grid[i][j - 1];
                }
                grid[i][j] = min(top, left) + 1;
            }
        }
        if(!one || one == n * n){
            return -1;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) continue;
                int bottom = inf, right = inf;
                if (i + 1 < m){
                    bottom = grid[i + 1][j];
                }
                if (j + 1 < n){
                    right = grid[i][j + 1];
                }
                grid[i][j] = min(grid[i][j], min(bottom, right) + 1);
                res = max(res, grid[i][j]);
            }
        }
        return res - 1;
    }
};
