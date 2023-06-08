class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = n * m;
        while(n > 0) {
            while(m > 0 && grid[grid.size() - n][m - 1] < 0) {
                m--;
            }
            res -= m, n--;
        }
        return res;
    }
};