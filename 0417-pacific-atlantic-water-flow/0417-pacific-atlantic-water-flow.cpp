class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>>& heights){
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < heights.size() && dy < heights[0].size() && heights[x][y] <= heights[dx][dy] && !vis[dx][dy]){
                dfs(dx, dy, vis, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> atlantic(n, vector<bool> (m)), pacific(n, vector<bool> (m));
        for (int i = 0; i < n; i++)
        {
            dfs(i, 0, pacific, heights);
            dfs(i, m - 1, atlantic, heights);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(0, i, pacific, heights);
            dfs(n - 1, i, atlantic, heights);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};