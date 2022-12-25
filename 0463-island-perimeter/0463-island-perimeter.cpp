class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int &res){
        if(i < 0 || j < 0 || i == n || j == m || !grid[i][j]){
            return 1;
        }
        if(grid[i][j] == -1) return 0;

        grid[i][j] = -1;
        res += dfs(i-1, j, n, m, grid, res) +
        dfs(i, j-1, n, m, grid, res) +
        dfs(i+1, j, n, m, grid, res) +
        dfs(i, j+1, n, m, grid, res);
        
        return 0;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]){
                    dfs(i, j, n, m, grid, res);
                    return res;
                }
            }
        }
        return 0;
    }
};