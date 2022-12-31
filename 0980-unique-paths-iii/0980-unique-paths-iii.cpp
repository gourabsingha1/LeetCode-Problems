class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int currSteps, int &steps) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == -1){
            return 0;
        }
        if(grid[i][j] == 2){
            return currSteps == steps;
        }
        grid[i][j] = -1;
        int paths = dfs(i - 1, j, grid, currSteps + 1, steps) +
        dfs(i, j - 1, grid, currSteps + 1, steps) +
        dfs(i + 1, j, grid, currSteps + 1, steps) +
        dfs(i, j + 1, grid, currSteps + 1, steps);
        grid[i][j] = 0;

        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int res = 0, steps = 0, x, y;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] != -1) steps++;
                if(grid[i][j] == 1) x = i, y = j;
            }
        }
        return dfs(x, y, grid, 1, steps);
    }
};