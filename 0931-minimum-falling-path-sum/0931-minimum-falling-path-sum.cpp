// for mat[i][j], store its val + min of top, topAdjLeft & topAdjRight

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int mn = matrix[i - 1][j];
                if(j > 0)  {
                    mn = min(mn, matrix[i - 1][j - 1]);
                }
                if(j + 1 < m) {
                    mn = min(mn, matrix[i - 1][j + 1]);
                }
                matrix[i][j] += mn;
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};