class Solution {
public:
    void dfs(int i, int j, int curr, vector<vector<int>>& grid, int &res){
        res = max(res, curr);
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || !grid[i][j]) return;
        int x = grid[i][j];
        grid[i][j] = 0;
        dfs(i + 1, j, curr + x, grid, res);
        dfs(i, j + 1, curr + x, grid, res);
        dfs(i - 1, j, curr + x, grid, res);
        dfs(i, j - 1, curr + x, grid, res);
        grid[i][j] = x;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int temp = 0;
                if(grid[i][j]) dfs(i, j, 0, grid, temp);
                res = max(res, temp);
            }
        }
        return res;
    }
};
