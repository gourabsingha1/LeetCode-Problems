// try all paths
// increase res only when it goes out of boundary

class Solution {
public:
    const int M = 1e9 + 7;
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up
    int dp[51][51][51];

    int helper(int& m, int& n, int maxMove, int x, int y) {
        if(maxMove == 0) {
            return 0;
        }
        if(dp[x][y][maxMove] != -1) {
            return dp[x][y][maxMove];
        }

        int res = 0;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < m && dy < n) {
                res = (res + helper(m, n, maxMove - 1, dx, dy)) % M;
            }
            else {
                res = (res + 1) % M;
            }
        }
        return dp[x][y][maxMove] = res;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(m, n, maxMove, startRow, startColumn);
    }
};