class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid, int &sum) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size()){
            return 0;
        }
        if(!grid[i][j]) return 1;
        grid[i][j] = 0;
        sum++;

        return dfs(i - 1, j, grid, sum) & dfs(i, j - 1, grid, sum) & dfs(i + 1, j, grid, sum) & dfs(i, j + 1, grid, sum);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j]){
                    int sum = 0;
                    if(dfs(i, j, grid, sum)){
                        res += sum;
                    }
                }
            }
        }
        return res;
    }
};