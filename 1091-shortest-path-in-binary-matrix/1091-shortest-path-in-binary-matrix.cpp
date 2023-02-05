class Solution {
public:
    int bfs(vector<vector<int>>& grid){
        if(grid[0][0]) return -1;
        int n = grid.size(), res = 1;
        queue<vector<int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        vector<vector<int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
        while(q.size()){
            int t = q.size();
            while(t--){
                int x = q.front()[0], y = q.front()[1];
                q.pop();
                if(x == n - 1 && y == n - 1){
                    return res;
                }
                for (int i = 0; i < dir.size(); i++)
                {
                    int dx = x + dir[i][0], dy = y + dir[i][1];
                    if(dx >= 0 && dy >= 0 && dx < n && dy < n && !grid[dx][dy]){
                        q.push({dx, dy});
                        grid[dx][dy] = 1;
                    }
                }
            }
            res++;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};