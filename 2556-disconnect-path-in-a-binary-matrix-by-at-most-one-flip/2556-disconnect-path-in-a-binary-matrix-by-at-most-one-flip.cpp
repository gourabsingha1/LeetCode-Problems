// in first dfs, set all values of the path to 0
// so that in next dfs we can check whether another path exists

class Solution {
public:
    vector<int> dir = {1, 0, 1}; // right, down, left, up

    bool dfs(int x, int y, vector<vector<int>>& grid) {
        if(x == grid.size() - 1 && y == grid[0].size() - 1) {
            return 1;
        }

        bool res = 0;
        grid[x][y] = 0;
        for (int i = 0; i < 2; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy]) {
                res |= dfs(dx, dy, grid);
                if(res) {
                    break;
                }
            }
        }
        return res;
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if(!dfs(0, 0, grid)) {
            return 1;
        }

        grid[0][0] = 1;
        return !dfs(0, 0, grid);
    }
};