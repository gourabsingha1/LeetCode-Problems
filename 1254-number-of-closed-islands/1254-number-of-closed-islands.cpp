class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    bool dfs(int x, int y, vector<vector<int>>& grid){
        grid[x][y] = 1;
        bool temp = 1;
        if(x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1){
            temp = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && !grid[dx][dy]){
                temp &= dfs(dx, dy, grid);
            }
        }
        return temp;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(!grid[i][j]){
                    res += dfs(i, j, grid);
                }
            }
        }
        return res;
    }
};