// 2D Scanline Algorithm
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> pre(n, vector<int> (n, 0));
        for (int i = 0; i < queries.size(); i++)
        {
            int r1 = queries[i][0], c1 = queries[i][1], r2 = queries[i][2], c2 = queries[i][3];
            pre[r1][c1]++;
            if(c2 + 1 < n) pre[r1][c2 + 1]--;
            if(r2 + 1 < n) pre[r2 + 1][c1]--;
            if(r2 + 1 < n && c2 + 1 < n) pre[r2 + 1][c2 + 1]++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                pre[i][j] += pre[i][j - 1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                pre[j][i] += pre[j - 1][i];
            }
        }
        return pre;
    }
};