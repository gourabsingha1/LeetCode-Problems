class Solution {
public:
    int helper(int i, int j, bool player1, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j][player1] != -1) {
            return dp[i][j][player1];
        }

        int res = 0;
        // player1 wants to maximize its score
        if(player1) {
            int takeLeft = nums[i] + helper(i + 1, j, !player1, nums, dp);
            int takeRight = nums[j] + helper(i, j - 1, !player1, nums, dp);
            res = max(takeLeft, takeRight);
        }
        // player2 wants to minimize player1's score
        else {
            int takeLeft = -nums[i] + helper(i + 1, j, !player1, nums, dp);
            int takeRight = -nums[j] + helper(i, j - 1, !player1, nums, dp);
            res = min(takeLeft, takeRight);
        }
        return dp[i][j][player1] = res;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));
        return helper(0, n - 1, 1, nums, dp) >= 0;
    }
};