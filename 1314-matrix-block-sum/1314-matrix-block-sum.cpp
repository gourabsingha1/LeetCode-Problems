class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> answer(n, vector<int> (m));
        vector<vector<int>> pre(n + 1, vector<int> (m + 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pre[i + 1][j + 1] += mat[i][j] + pre[i + 1][j];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pre[i + 1][j + 1] += pre[i][j + 1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int row1 = max(i + 1 - k, 1), col1 = max(j + 1 - k, 1), row2 = min(i + 1 + k, n), col2 = min(j + 1 + k, m);
                int res = pre[row2][col2] - pre[row1 - 1][col2] - pre[row2][col1 - 1] + pre[row1 - 1][col1 - 1];
                answer[i][j] = res;
            }
        }
        return answer;
    }
};