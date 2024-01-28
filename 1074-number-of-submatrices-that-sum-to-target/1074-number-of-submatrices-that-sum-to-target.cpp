// 304. Range Sum Query 2D - Immutable
// check all possible submatrices. O(N * N * M * M)

class NumMatrix {
public:
    vector<vector<int>> pre;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        pre.resize(n + 1, vector<int> (m + 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pre[i + 1][j + 1] += matrix[i][j] + pre[i + 1][j];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pre[i + 1][j + 1] += pre[i][j + 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, col1++, row2++, col2++;
        int res = pre[row2][col2] - pre[row1 - 1][col2] - pre[row2][col1 - 1] + pre[row1 - 1][col1 - 1];
        return res;
    }
};

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res = 0, n = matrix.size(), m = matrix[0].size();
        NumMatrix NM(matrix);
        for (int row2 = 0; row2 < n; row2++)
        {
            for (int col2 = 0; col2 < m; col2++)
            {
                for (int row1 = 0; row1 <= row2; row1++)
                {
                    for (int col1 = 0; col1 <= col2; col1++)
                    {
                        res += NM.sumRegion(row1, col1, row2, col2) == target;
                    }
                }
            }
        }
        return res;
    }
};