class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), res = 2;
        vector<vector<int>> dp(n, vector<int> (1003, 1));
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j] + 501;
                if(dp[i][diff] != -1) {
                    dp[i][diff] = 1 + dp[j][diff];
                }
                else {
                    dp[i][diff] = 2;
                }
                res = max(res, dp[i][diff]);
            }
        }
        return res;
    }
};