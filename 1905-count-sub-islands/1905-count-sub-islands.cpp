class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    bool dfs(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        grid2[x][y] = 0;
        bool temp = 1;
        if(!grid1[x][y]){
            temp = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < grid2.size() && dy < grid2[0].size() && grid2[dx][dy]){
                temp &= dfs(dx, dy, grid1, grid2);
            }
        }
        return temp;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res = 0;
        for (int i = 0; i < grid2.size(); i++)
        {
            for (int j = 0; j < grid2[0].size(); j++)
            {
                if(grid2[i][j]){
                    res += dfs(i, j, grid1, grid2);
                }
            }
        }
        return res;
    }
};