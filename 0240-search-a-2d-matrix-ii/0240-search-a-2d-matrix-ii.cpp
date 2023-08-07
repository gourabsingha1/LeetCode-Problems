class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            int low = 0, high = m - 1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(matrix[i][mid] == target) {
                    return 1;
                }
                else if(matrix[i][mid] < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return 0;
    }
};