class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), low = 0, high = n * m - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int x = mid / m, y = mid % m;
            if(matrix[x][y] == target) {
                return 1;
            }
            else if(matrix[x][y] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return 0;
    }
};