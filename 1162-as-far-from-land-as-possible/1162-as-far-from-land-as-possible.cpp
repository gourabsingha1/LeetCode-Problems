class Solution {
public:
    int bfs(vector<vector<int>> grid){
        int levels = -1, n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j]){
                    q.push({i, j});
                }
            }
        }
        if(!q.size() || q.size() == n * n){
            return -1;
        }
        vector<int> dir = {0, 1, 0, -1, 0};
        while(q.size()){
            levels++;
            int t = q.size();
            while(t--){
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int dx = x + dir[i], dy = y + dir[i + 1];
                    if(isValid(dx, dy, n, n) && !grid[dx][dy]){
                        q.push({dx, dy});
                        grid[dx][dy] = 1;
                    }
                }
            }
        }
        return levels;
    }
    bool isValid(int &i, int &j, int &n, int &m){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int maxDistance(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};