class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    bool isPossible(int mid, vector<vector<int>> grid, vector<vector<int>>& cells) {
        int n = grid.size(), m = grid[0].size();
        // setting water cells uptil mid index of cells vector
        for (int i = 0; i < mid; i++)
        {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            grid[x][y] = 1;
        }
        // pushing first row in queue if it is land cell
        queue<pair<int, int>> q; // x, y
        for (int j = 0; j < m; j++)
        {
            if(grid[0][j] == 0) {
                q.push({0, j});
                grid[0][j] = 1;
            }
        }
        // if any cell reaches the bottom row, then it is possible
        while(q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy] == 0){
                    if(dx == n - 1) {
                        return 1;
                    }
                    q.push({dx, dy});
                    grid[dx][dy] = 1;
                }
            }
        }
        return 0;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int> (col, 0));
        int low = 0, high = cells.size() - 1;
        while(low <= high) {
            int mid = high + (low - high) / 2;
            if(isPossible(mid, grid, cells)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};