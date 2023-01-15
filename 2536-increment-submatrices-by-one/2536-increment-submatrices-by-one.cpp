class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int> (n, 0));
        int mat[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = 0;
            }
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int r1 = queries[i][0], c1 = queries[i][1], r2 = queries[i][2], c2 = queries[i][3];
            for (int j = r1; j <= r2; j++)
            {
                for (int k = c1; k <= c2; k++)
                {
                    mat[j][k]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = mat[i][j];
            }
        }
        return res;
    }
};