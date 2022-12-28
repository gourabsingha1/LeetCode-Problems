class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int dp[n][m];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++){
            if(obstacleGrid[i][0]) break;
            dp[i][0] = 1;
        }
        for (int i = 0; i < m; i++){
            if(obstacleGrid[0][i]) break;
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if(!obstacleGrid[i][j]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};