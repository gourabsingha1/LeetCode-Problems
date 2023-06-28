// it takes only less than or equal to 2 days to disconnect any island
// 0 = no island
// 1 = connected by 1 bridge
// 2 = otherwise
// for 1, make any land cell a water cell then if there are 2 islands then res = 1

class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    void dfs(int x, int y, vector<vector<int>>& grid) {
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy]){
                dfs(dx, dy, grid);
            }
        }
    }

    int countIslands(vector<vector<int>> grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]) {
                    dfs(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }

    int minDays(vector<vector<int>>& grid) {
        if(countIslands(grid) != 1) {
            return 0;
        }

        int n = grid.size(), m = grid[0].size(), lands = 0, islands = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]) {
                    grid[i][j] = 0;
                    if(countIslands(grid) > 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                    lands++;
                }
            }
        }
        if(lands == 1) {
            return 1;
        }
        return 2;
    }
};