class Solution{
public:
    int maxDistance(vector<vector<int>> &grid){
        int n = grid.size(), ans = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        if (q.size() == 0 || q.size() == n * n)
            return -1;

        vector<pair<int, int>> dirc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto [i, j] = q.front();
                q.pop();
                for (auto [dx, dy] : dirc)
                {
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0)
                    {
                        grid[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            ans++;
        }
        return ans - 1;
    }
};