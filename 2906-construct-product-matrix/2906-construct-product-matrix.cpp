// 1D prefix suffix array then covert it into 2D

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), size = n * m, M = 12345;
        vector<long long> pre(size, 1), suf(size, 1), nums;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                nums.push_back(grid[i][j]);
            }
        }
        pre[0] = nums[0] % M;
        for (int i = 1; i < size; i++)
        {
            pre[i] = (1LL * pre[i - 1] * nums[i]) % M;
        }
        suf[size - 1] = nums[size - 1] % M;
        for (int i = size - 2; i >= 0; i--)
        {
            suf[i] = (1LL * suf[i + 1] * nums[i]) % M;
        }
        
        for (int i = 0; i < size; i++)
        {
            int left = 1;
            if(i > 0) left = pre[i - 1];
            int right = 1;
            if(i + 1 < size) right = suf[i + 1];
            grid[i / m][i % m] = (1LL * left * right) % M;
        }
        return grid;
    }
};