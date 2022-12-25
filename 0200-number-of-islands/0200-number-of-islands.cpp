class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i == n || j == m || grid[i][j] == '0'){
            return 0;
        }
        grid[i][j] = '0';
        
        dfs(i-1, j, n, m, grid);
        dfs(i, j-1, n, m, grid);
        dfs(i+1, j, n, m, grid);
        dfs(i, j+1, n, m, grid);
        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]){
                    ans += dfs(i, j, n, m, grid);
                }
            }
        }
        return ans;
    }
};