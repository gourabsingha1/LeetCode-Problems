// use dfs to mark an island and push them in queue then start bfs from it to find the other island in shortest distance
class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
    void dfs(int x, int y, vector<vector<int>>& grid){
        grid[x][y] = 2;
        q.push({x, y});
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy] == 1){
                dfs(dx, dy, grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int res = 0, flag = 1;
        for (int i = 0; i < grid.size() && flag; i++)
        {
            for (int j = 0; j < grid[0].size() && flag; j++)
            {
                if(grid[i][j]){
                    dfs(i, j, grid);
                    flag = 0;
                }
            }
        }
        while(q.size()) {
            int t = q.size();
            while(t--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int dx = x + dir[i], dy = y + dir[i + 1];
                    if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy] != 2){
                        if(grid[dx][dy] == 1){
                            return res;
                        }
                        q.push({dx, dy});
                        grid[dx][dy] = 2;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};