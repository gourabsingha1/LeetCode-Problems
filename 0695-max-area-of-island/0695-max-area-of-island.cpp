class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    void dfs(int& cnt, int x, int y, vector<vector<int>>& grid){
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy]){
                cnt++;
                dfs(cnt, dx, dy, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j]){
                    int cnt = 1;
                    dfs(cnt, i, j, grid);
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};