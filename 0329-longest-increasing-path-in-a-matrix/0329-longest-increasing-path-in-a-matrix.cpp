class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int dfs(vector<vector<int>> &dp, int x, int y, vector<vector<int>> &matrix) {
        if(dp[x][y]){
            return dp[x][y];
        }
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < matrix.size() && dy < matrix[0].size() && matrix[dx][dy] > matrix[x][y]){
                dp[x][y] = max(dp[x][y], 1 + dfs(dp, dx, dy, matrix));
            }
        }
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res = max(res, dfs(dp, i, j, matrix));
            }
        }
        return res + 1;
    }
};