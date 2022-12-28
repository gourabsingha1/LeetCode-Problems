class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) return 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        for (int i = 0; i < n; i++){
            if(obstacleGrid[i][0]){
                for (int j = i; j < n; j++) obstacleGrid[j][0] = 0;
                break;
            }
            obstacleGrid[i][0] = 1;
        }
        for (int i = 1; i < m; i++){
            if(obstacleGrid[0][i]){
                for (int j = i; j < m; j++) obstacleGrid[0][j] = 0;
                break;
            }
            obstacleGrid[0][i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                obstacleGrid[i][j] = !obstacleGrid[i][j];
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if(obstacleGrid[i][j]){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        
        return obstacleGrid[n-1][m-1];
    }
};