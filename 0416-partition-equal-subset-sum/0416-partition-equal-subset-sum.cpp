class Solution {
public:
    // tabulation
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) {
            return 0;
        }
        sum /= 2;
        vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if(j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    bool take = 0;
                    if(j - nums[i] >= 0) {
                        take = dp[i - 1][j - nums[i]];
                    }
                    bool notTake = dp[i - 1][j];
                    dp[i][j] = take || notTake;
                }
            }
        }
        return dp[n - 1][sum];
    }
};