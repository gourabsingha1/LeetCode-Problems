class Solution {
public:
    int M = 1e9 + 7;
    int helper(int i, int j, vector<vector<int>>& pre, vector<string>& pizza, int k, vector<vector<vector<int>>>& dp) {
        if(pre[i][j] == 0) {
            return 0;
        }
        if(k == 0) {
            return 1;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int res = 0;
        for (int r = i + 1; r < pizza.size(); r++)
        {
            if(pre[i][j] - pre[r][j] > 0) {
                res = (res + helper(r, j, pre, pizza, k - 1, dp)) % M;
            }
        }
        for (int c = j + 1; c < pizza[0].size(); c++)
        {
            if(pre[i][j] - pre[i][c] > 0) {
                res = (res + helper(i, c, pre, pizza, k - 1, dp)) % M;
            }
        }
        return dp[i][j][k] = res;
    }
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size();
        vector<vector<int>> pre(n + 1, vector<int> (m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                pre[i][j] = pre[i][j + 1] + pre[i + 1][j] - pre[i + 1][j + 1] + (pizza[i][j] == 'A');
            }
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k, -1)));
        return helper(0, 0, pre, pizza, k - 1, dp);
    }
};