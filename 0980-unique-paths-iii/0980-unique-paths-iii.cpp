class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int &steps) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == -1){
            return 0;
        }
        if(grid[i][j] == 2){
            return steps == -1;
        }
        grid[i][j] = -1;
        steps--;
        int paths = dfs(i - 1, j, grid, steps) +
        dfs(i, j - 1, grid, steps) +
        dfs(i + 1, j, grid, steps) +
        dfs(i, j + 1, grid, steps);
        grid[i][j] = 0;
        steps++;

        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int res = 0, steps = 0, x, y;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(!grid[i][j]) steps++;
                if(grid[i][j] == 1) x = i, y = j;
            }
        }
        return dfs(x, y, grid, steps);
    }
};