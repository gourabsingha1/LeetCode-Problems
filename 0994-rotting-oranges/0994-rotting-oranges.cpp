class Solution {
public:
    void check(int i, int j, int n, int m, vector<vector<int>> &grid, queue<pair<int,int>> &q, int &fresh){
        if(i < 0 || j < 0 || i == n || j == m || !grid[i][j]){
            return;
        }
        q.push({i, j});
        grid[i][j] = 0;
        fresh--;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = -1, fresh = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2){
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(!fresh) return 0;

        while(q.size()){
            int size = q.size();
            while(size--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                check(x-1, y, n, m, grid, q, fresh);
                check(x, y-1, n, m, grid, q, fresh);
                check(x+1, y, n, m, grid, q, fresh);
                check(x, y+1, n, m, grid, q, fresh);
            }
            res++;
        }
        if(fresh) return -1;
        return res;
    }
};