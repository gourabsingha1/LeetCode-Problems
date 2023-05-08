class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0, n = mat.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i == j || i + j + 1 == n) {
                    res += mat[i][j];
                }
            }
        }
        return res;
    }
};