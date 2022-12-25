class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int &res){
        if(i < 0 || j < 0 || i == n || j == m || !grid[i][j]){
            return;
        }
        res++;
        grid[i][j] = 0;
        dfs(i-1, j, n, m, grid, res);
        dfs(i, j-1, n, m, grid, res);
        dfs(i+1, j, n, m, grid, res);
        dfs(i, j+1, n, m, grid, res);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]){
                    int res = 0;
                    dfs(i, j, n, m, grid, res);
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};