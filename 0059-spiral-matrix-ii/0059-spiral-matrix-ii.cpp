class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int> (n));
        int up = 1, down = n - 2, left = 0, right = n - 1, num = 0;
        n = n * n;
        while(num < n) {
            // right
            for (int i = left; i <= right && num < n; i++)
            {
                mat[up - 1][i] = ++num;
            }
            // down
            for (int i = up; i <= down && num < n; i++)
            {
                mat[i][right] = ++num;
            }
            // left
            for (int i = right; i >= left && num < n; i--)
            {
                mat[down + 1][i] = ++num;
            }
            // up
            for (int i = down; i >= up && num < n; i--)
            {
                mat[i][left] = ++num;
            }
            left++, right--, up++, down--;
        }
        return mat;
    }
};