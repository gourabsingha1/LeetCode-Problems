class Solution {
public:
    vector<vector<int>> knightDir = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

    double helper(int& n, int k, int x, int y, vector<vector<vector<double>>>& dp) {
        if(k == 0) {
            return 1;
        }
        if(dp[x][y][k] != -1) {
            return dp[x][y][k];
        }

        double res = 0;
        for (int i = 0; i < 8; i++)
        {
            int dx = x + knightDir[i][0], dy = y + knightDir[i][1];
            if(dx >= 0 && dx < n && dy >= 0 && dy < n) {
                res += (1 / 8.0) * helper(n, k - 1, dx, dy, dp);
            }
        }
        return dp[x][y][k] = res;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double> (k + 1, -1)));
        return helper(n, k, row, column, dp);
    }
};