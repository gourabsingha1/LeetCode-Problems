class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> res;
        vector<int> row, col;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            int c = 0;
            for(auto &x : grid[i])
            {
                if(!x) c++;
            }
            row.push_back(n - 2*c);
        }
        for (int i = 0; i < m; i++)
        {
            int c = 0;
            for(int j = 0; j < n; j++)
            {
                if(!grid[j][i]) c++;
            }
            col.push_back(m - 2*c);
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for(int j = 0; j < m; j++)
            {
                v.push_back(row[i]+col[j]);
            }
            res.push_back(v);
        }
        return res;
    }
};