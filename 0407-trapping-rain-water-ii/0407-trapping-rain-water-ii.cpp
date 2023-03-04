class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size(), res = 0;
        vector<vector<bool>> vis(n, vector<bool> (m));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        // push borders first
        for (int i = 0; i < n; i++)
        {
            q.push({heightMap[i][0], i, 0}), q.push({heightMap[i][m - 1], i, m - 1});
            vis[i][0] = 1, vis[i][m - 1] = 1;
        }
        for (int i = 1; i < m - 1; i++)
        {
            q.push({heightMap[0][i], 0, i}), q.push({heightMap[n - 1][i], n - 1, i});
            vis[0][i] = 1, vis[n - 1][i] = 1;
        }
        // process the minimum height first
        while (q.size()) {
            int x = q.top()[1], y = q.top()[2];
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if(dx >= 0 && dy >= 0 && dx < n && dy < m && !vis[dx][dy]){
                    res += max(0, heightMap[x][y] - heightMap[dx][dy]);
                    heightMap[dx][dy] = max(heightMap[x][y], heightMap[dx][dy]);
                    q.push({heightMap[dx][dy], dx, dy});
                    vis[dx][dy] = 1;
                }
            }
        }
        return res;
    }
};