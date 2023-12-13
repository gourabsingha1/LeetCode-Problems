// row = upSum(prefix) + downSum(suffix) - mat[i][j]
// col = leftSum(prefix) + rightSum(suffix) - mat[i][j]

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res = 0, n = mat.size(), m = mat[0].size();
        vector<vector<int>> up(n, vector<int>(m)), down(n, vector<int>(m)), left(n, vector<int>(m)), right(n, vector<int>(m));
        for (int j = 0; j < m; j++)
        {
            up[0][j] = mat[0][j], down[n - 1][j] = mat[n - 1][j];
            for (int i = 1; i < n; i++)
            {
                up[i][j] = up[i - 1][j] + mat[i][j];
                down[n - 1 - i][j] = down[n - i][j] + mat[n - 1 - i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            left[i][0] = mat[i][0], right[i][m - 1] = mat[i][m - 1];
            for (int j = 1; j < m; j++)
            {
                left[i][j] = left[i][j - 1] + mat[i][j];
                right[i][m - 1 - j] = right[i][m - j] + mat[i][m - 1 - j];
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(mat[i][j]) {
                    int row = up[i][j] + down[i][j] - mat[i][j];
                    int col = left[i][j] + right[i][j] - mat[i][j];
                    if(row == 1 && col == 1) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};