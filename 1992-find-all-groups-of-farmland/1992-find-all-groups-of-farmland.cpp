class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    void dfs(int x, int y, int &r, int &c, vector<vector<int>>& land){
        land[x][y] = 0;
        r = max(r, x), c = max(c, y);
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < land.size() && dy < land[0].size() && land[dx][dy]){
                dfs(dx, dy, r, c, land);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[0].size(); j++)
            {
                if(land[i][j]){
                    int r = i, c = j;
                    dfs(i, j, r, c, land);
                    res.push_back({i, j, r, c});
                }
            }
        }
        return res;
    }
};