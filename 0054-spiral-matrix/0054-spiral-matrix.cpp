class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while(1) {
            int size = res.size();
            // right
            for (int i = left; i <= right && up <= down; i++)
            {
                res.push_back(matrix[up][i]);
            }
            // down
            for (int i = up + 1; i <= down - 1 && left <= right; i++)
            {
                res.push_back(matrix[i][right]);
            }
            // left
            for (int i = right; i >= left && up + 1 <= down; i--)
            {
                res.push_back(matrix[down][i]);
            }
            // up
            for (int i = down - 1; i >= up + 1 && left + 1 <= right; i--)
            {
                res.push_back(matrix[i][left]);
            }
            up++, left++, down--, right--;
            if(size == res.size()) break;
        }
        return res;
    }
};